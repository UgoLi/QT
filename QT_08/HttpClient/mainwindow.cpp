#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LoginDialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //当点击菜单工具条的菜单选项发送triggered
    connect(ui->menuBar,SIGNAL(triggered(QAction*)),
            this,SLOT(onTriggred(QAction*)));
    //点击文件菜单的下拉选项也会发送triggered
    connect(ui->menuFile,SIGNAL(triggered(QAction*)),
            this,SLOT(onTriggred(QAction*)));
    //隐藏下载进度条
    ui->progressBar->hide();

    manager = new QNetworkAccessManager(this);

    //点击界面链接,发送信号anchorClicked
    connect(ui->textBrowser,
            SIGNAL(anchorClicked(QUrl)),
            this,SLOT(onAnchorClicked(QUrl)));
    //向容器中添加所有想要支持下载的文件类型
    fileTpye << ".tar.gz" << ".tar.bz2" << ".xz";
    fileTpye << ".7z" << ".zip" << ".rar";
    fileTpye << ".txt" << ".dox" << ".pdf";
    fileTpye << ".jpg" << ".bmp" << ".gif";
    //...
}

MainWindow::~MainWindow()
{
    delete ui;
}

//处理菜单选项的槽函数
void MainWindow::onTriggred(QAction* action)
{
    //在状态栏显示当前菜单选项
    ui->statusBar->showMessage(action->text());
    if(action->menu() == ui->menuFull){
        showFullScreen();//全屏
    }
    else if(action->menu() == ui->menuNormal){
        showNormal();//恢复
    }
}

//向服务器发送其请求
void MainWindow::sendRequest(void)
{
    //发送请求之后返回响应对象，通过它处理响应数据
    reply = manager->get(*request);
    //发送请求之后，如果服务器要求登录认证，发送
    //信号authenticationRequired
    connect(manager,SIGNAL(authenticationRequired(
                QNetworkReply*,QAuthenticator*)),
            this,SLOT(onAuthenticationRequired(
                QNetworkReply*,QAuthenticator*)));
    //服务器返回响应数据时发送readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    //当响应数据接收完成，发送finished信号
    connect(reply,SIGNAL(finished()),
            this,SLOT(onFinished()));
}


//处理登录验证
void MainWindow::onAuthenticationRequired(
     QNetworkReply *, QAuthenticator * authenticator){
    //authenticator->setUser("tarenacode");
    //authenticator->setPassword("code_2013");
    //练习：增加登录对话框
    //弹出登录对话框
    LoginDialog login(this);
    //如果点击ok退出事件循环，则进行登录认证
    if(login.exec() == QDialog::Accepted){
        QString username = login.getUserName();
        QString passwd = login.getPasswd();
        authenticator->setUser(username);
        authenticator->setPassword(passwd);
    }
}
//接收响应数据的槽函数
void MainWindow::onReadyRead(void)
{
    //读取响应数据
    QString replyText = reply->readAll();
    //显示数据到界面
    ui->textBrowser->setText(replyText);
    //保存当前网络地址（url）
    currentUrl = reply->url();
}
//接收响应数据完成对应槽函数
void MainWindow::onFinished(void)
{
    reply->deleteLater();
}

//处理链接
void MainWindow::onAnchorClicked(const QUrl& url)
{
    /*
    点击的url: "CSDCode/"
    当前的url: "http://code.tarena.com.cn/"
    进入新的url：http://code.tarena.com.cn/CSDCode/
    */
    //qDebug() << "点击的url:" << url.toString();
    //qDebug() << "当前的url:" << currentUrl.toString();
    QUrl newUrl;
    //处理非"../"链接
    if(url.toString() != "../"){
        newUrl = currentUrl.toString()+url.toString();
    }
    else{//处理"../"链接
        if(currentUrl.toString() ==
                "http://code.tarena.com.cn/"){
            //如果在顶层目录链接中，不处理
            return;
        }
        else{
        //eg:http://code.tarena.com.cn/test/test2/
        //去掉最后一级目录
        //newUrl=http://code.tarena.com.cn/test/
            //1)找到倒数第二次出现'/'位置
            int pos =
            currentUrl.toString().lastIndexOf("/",-2);
            //2)字符串截断，去掉最后一级路径
            newUrl =
            currentUrl.toString().mid(0,pos+1);
        }
    }
    //判断当前新的url是不是要下载的文件，如果是
    //则执行文件的下载操作
    foreach(QString type,fileTpye){
        int res = url.toString().lastIndexOf(type);
        if(res >= 0){//如果是要下载文件
            qDebug() << "下载文件的操作:"
                     << newUrl.toString();
            downloadFile(newUrl);

            return;
        }
    }
    //如果不是要下载文件，则进入新的链接并显示
    //设置请求地址为newUrl
    request->setUrl(newUrl);
    //发送新的请求
    sendRequest();

}
//下载文件
void MainWindow::downloadFile(const QUrl& fileUrl)
{
    //根据文件url，在本地创建同名文件
    //eg:fileUrl==>http://.../Qt/ppt.zip
    //path():.../Qt/ppt.zip
    //fileName()://ppt.zip
    //获取文件名
    QFileInfo fileInfo(fileUrl.path());
    QString filename = fileInfo.fileName();
    //创建同名的文件，并打开
    file = new QFile(filename,this);
    file->open(QIODevice::WriteOnly);

    //发送获取文件请求
    request->setUrl(fileUrl);
    reply = manager->get(*request);
    //这时服务器返回的响应数据就是文件内容，响应数据
    //到来以后发送readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(receiveFile()));
    //响应数据接收完成（文件下载完成）,发送信号finished
    connect(reply,SIGNAL(finished()),
            this,SLOT(receiveFileFinished()));
    //文件下载过程中，不断产生信号downloadProgress,表示
    //当前的下载进度,参数（已收到字节数/总字节数）;
    connect(reply,
         SIGNAL(downloadProgress(qint64,qint64)),
         this,
         SLOT(updateDownloadProgress(qint64,qint64)));
    //显示进度条组件
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
//接收文件内容的槽函数
void MainWindow::receiveFile(void)
{
    //qDebug() << "正在下载文件...";
    //读取响应数据同时写到对应文件中
    file->write(reply->readAll());
}
//下载文件完成对应的槽函数
void  MainWindow::receiveFileFinished(void)
{
    qDebug() << "文件下载完成...";
    //刷新文件缓冲区
    file->flush();
    //关闭文件
    file->close();
    //删除reply对象
    reply->deleteLater();
    //隐藏进度条
    ui->progressBar->hide();
}
//更新显示进度条槽函数
void MainWindow::updateDownloadProgress(
        qint64 size,qint64 allSize)
{
    ui->progressBar->setMaximum(allSize);
    ui->progressBar->setValue(size);
}


//界面刷新槽函数
void MainWindow::on_lineEdit_editingFinished()
{
    //qDebug()<<"界面刷新!";
    //初始化请求
    //eg:http://192.168.0.70/
    //"http://code.tarena.com.cn/"
    request = new QNetworkRequest(
             QUrl(ui->lineEdit->text()));
    //发送请求
    sendRequest();
}
