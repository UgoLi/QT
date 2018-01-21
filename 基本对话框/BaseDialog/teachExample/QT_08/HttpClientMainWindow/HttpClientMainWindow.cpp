#include "HttpClientMainWindow.h"
#include "ui_HttpClientMainWindow.h"

HttpClientMainWindow::HttpClientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HttpClientMainWindow)
{
    ui->setupUi(this);
    hide();

    manager=new QNetworkAccessManager(this);
    //初始化请求
    request=new QNetworkRequest(QUrl("http://code.tarena.com.cn/"));
    //发送请求,余下*request,*reply操作封装到以下函数执行
    sendRequest();

    //点击界面链接，发送信号achorclick
    connect(ui->textBrowser,SIGNAL(anchorClicked(QUrl)),
            this,SLOT(onAchorClicked(QUrl)));

    //向容器中添加所有想要支持下载的文件类型
    fileTpye<<".tar.gz"<<".tar.bz2"<<".xz"<<".7z"<<".zip";
    fileTpye<<".rar"<<".txt"<<".dox"<<".pdf"<<".jpg"<<".bmp"<<".gif";
    //...
}

HttpClientMainWindow::~HttpClientMainWindow()
{
    delete ui;
    qDebug()<<"HttpClientMainWindow::~HttpClientMainWindow";
}

//向服务器发送其请求
void HttpClientMainWindow::sendRequest(void)
{
    //发送请求后返回响应对象
    reply=manager->get(*request);
    //如果服务器需要登陆认证，发送信号
    connect(manager,SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
            this,SLOT(onAuthenticationRequired(QNetworkReply*,QAuthenticator*)));
    //服务器返回响应数据时发送readyRead信号
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    //当响应数据接收完成，发送finished信号
    connect(reply,SIGNAL(finished()),
            this,SLOT(onFinished()));

}

//处理登陆验证
void HttpClientMainWindow::onAuthenticationRequired(
        QNetworkReply*,QAuthenticator* authenticator)
{
    //authenticator->setUser("tarenacode");
    //authenticator->setPassword("code_2013");
    //弹出登录对话框
    LoginDialog login(this);
    //如果点击ok退出事件循环，则进行登录认证
    if(login.exec()==QDialog::Accepted){
        QString username=login.getUsername();
        QString passwd=login.getPasswd();
        authenticator->setUser(username);
        authenticator->setPassword(passwd);
    }
}

//接受响应数据的槽函数
void HttpClientMainWindow::onReadyRead(void)
{
    //读取响应数据
    QString replyText=reply->readAll();
    //显示到UI
    ui->textBrowser->setText(replyText);
    //保存当前网址(url)
    currentUrl=reply->url();
}

//数据接收完成时对应的槽函数
void HttpClientMainWindow::onFinished(void)
{
    reply->deleteLater();
}

//处理链接
void HttpClientMainWindow::onAchorClicked(const QUrl& url)
{
    /*
    点击的url： "AIDCode/"
    当前的url： "http://code.tarena.com.cn/"
    进入新的url: "http://code.tarena.com.cn/AIDCode/"
    */
    //qDebug()<<"点击的url："<<url.toString();
    //qDebug()<<"当前的url："<<currentUrl.toString();

    QUrl newUrl;
    //处理非"../"链接
    if(url.toString()!="../"){
        newUrl=currentUrl.toString()+url.toString();
    }else{
        if(currentUrl.toString()=="http://code.tarena.com.cn/"){
            //如果在顶层目录中不做处理
            return;
        }else {
            //去掉最后一级目录
            //找到倒数第二次出现'/'的位置
            int pos=currentUrl.toString().lastIndexOf("/",-2);
            //字符串截断，去掉最后一级路径
            newUrl=currentUrl.toString().mid(0,pos+1);
        }
    }
    ui->lineEdit->setText(newUrl.toString());
    //判断当前的url是不是要下载的文件，如果是，则执行文件的下载
    foreach (QString type, fileTpye) {
        int res=url.toString().lastIndexOf(type);
        if(res>=0){//如果是要下载文件类型
            qDebug()<<"下载文件的操作:"<<newUrl.toString();
            qDebug()<<"current threadId:"<<QThread::currentThreadId();


            downloadThread=new DownloadFileThread(&newUrl,manager);
            showDownloadProgress=new showDownloadProgressDialog(this);
            QThread* thread=new QThread;

            //下载控制界面设置
            QString filename=newUrl.toString();
            QString downThreadId=QString("%1").asprintf("%p",thread->currentThreadId());
            showDownloadProgress->setUiInfo(filename,downThreadId);
            //界面更新,后台信号与界面槽函数绑定
            connect(downloadThread->reply,SIGNAL(downloadProgress(qint64,qint64)),
                    showDownloadProgress,SLOT(updateDownloadProgress(qint64,qint64)));
            connect(downloadThread,SIGNAL(isDownloading(QString const&)),
                    showDownloadProgress,SLOT(onIsDownloading(QString const&)));
            connect(downloadThread,SIGNAL(isFinished()),
                    showDownloadProgress,SLOT(onIsFinished()));

            downloadThread->moveToThread(thread);
            showDownloadProgress->show();
            thread->start();
            return;
        }
    }//如果不是要下载的文件，则进入新的连接并显示

    //设置新的请求地址
    request->setUrl(newUrl);
    //发送新的请求
    sendRequest();
}


//url内容改变槽函数
void HttpClientMainWindow::on_lineEdit_returnPressed()
{
    //刷新请求
    request=new QNetworkRequest(QUrl(ui->lineEdit->text()));
    //发送请求,余下*request,*reply操作封装到以下函数执行
    sendRequest();
}

void HttpClientMainWindow::closeEvent(QCloseEvent* event)
{
    switch (QMessageBox::question(
                this,"Question消息框","是否退出当前界面,回到BaseDialog界面?",
                QMessageBox::Ok|QMessageBox::Cancel,
                QMessageBox::Ok)) {
    case QMessageBox::Ok:
        //close();
        event->accept();
        parentWidget()->show();
        deleteLater();
        break;
    case QMessageBox::Cancel:
        event->ignore();
        break;
    default:
        break;
    }
}


