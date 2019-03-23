#include "TcpClientDialog.h"
#include "ui_TcpClientDialog.h"


TcpClientDialog::TcpClientDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::TcpClientDialog)
{
    ui->setupUi(this);
    status=false;
    //连接服务器，成功时发送connected信号
    connect(&tcpSocket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    //断开服务器，发送disConnected信号
    connect(&tcpSocket,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    //网络异常,发送error信号
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(onError(QAbstractSocket::SocketError)));
    //当收到服务器的消息时，发送readyRead信号
    connect(&tcpSocket,SIGNAL(readyRead()),
            this,SLOT(onReadyread()));
}

TcpClientDialog::~TcpClientDialog()
{
    delete ui;
    qDebug()<<"TcpClientDialog::~TcpClientDialog";
}

//连接服务器槽函数
void TcpClientDialog::on_connectButton_clicked()
{
    if(status==false){
        //如果当前是离线状态，则建立连接
        //获取UI界面输入的IP
        QString ip=ui->serverIpEdit->text();
        //设置服务器IP地址
        if(serverIp.setAddress(ip)==false){
            QMessageBox::critical(this,"Error","IP地址错误");
            return;
        }
        //获取端口
        serverPort=ui->serverPortEdit->text().toShort();
        if(serverPort==0){
            QMessageBox::critical(this,"Error","端口号错误");
            return;
        }
        //获取用户昵称
        username=ui->usernameEdit->text();
        if(username==""){
            QMessageBox::critical(this,"Error","用户名错误");
            return;
        }
        //和服务器建立连接
        //成功，发送信号:connected
        //失败，发送信号:error
        tcpSocket.connectToHost(serverIp,serverPort);

        //标记当前为在线状态
        status=true;
    }else{
        //如果当前时在线状态，则断开连接
        //向服务器发送断开连接的提示消息
        QString msg=username+": 离开聊天室";
        tcpSocket.write(msg.toLocal8Bit());
        //断开和服务器连接
        tcpSocket.disconnectFromHost();
        //标记离线状态
        status=false;
    }
}

//发送按钮槽函数
void TcpClientDialog::on_sendButton_clicked()
{
    //获取用户输入的聊天消息
    QString msg=username+": "+ui->messageEdit->text();
    tcpSocket.write(msg.toLocal8Bit());
    //清空输入消息
    ui->messageEdit->clear();
}

//与服务器连接时被执行
void TcpClientDialog::onConnected(void)
{
    qDebug("%s",__func__);
    //使能，发送消息按钮
    ui->sendButton->setEnabled(true);
    //连接服务器--》离开服务器
    ui->connectButton->setText("离开服务器");
    //禁用：ip、port、昵称
    ui->serverIpEdit->setEnabled(false);
    ui->serverPortEdit->setEnabled(false);
    ui->usernameEdit->setEnabled(false);
    //向服务器发送：加入聊天室的提示消息
    QString msg=username+": 进入聊天室";
    //tolocal8Bit:QString-->QByteArray
    tcpSocket.write(msg.toLocal8Bit());
}

//与服务器连接时被执行
void TcpClientDialog::onDisconnected(void)
{
    //禁用，发送消息按钮
    ui->sendButton->setEnabled(false);
    //连接服务器--》离开服务器
    ui->connectButton->setText("连接服务器");
    //使能：ip、port、昵称
    ui->serverIpEdit->setEnabled(true);
    ui->serverPortEdit->setEnabled(true);
    ui->usernameEdit->setEnabled(true);
}

//网络异常时被执行
void TcpClientDialog::onError(QAbstractSocket::SocketError)
{
    //打印套接字错误信息
    qDebug()<<tcpSocket.errorString();
    QMessageBox::critical(this,"Error",tcpSocket.errorString());
}

//收到服务器的消息时
void TcpClientDialog::onReadyread(void)
{
    //bytesAvailable() 获取当前套接字的有效的数据个数
    if(tcpSocket.bytesAvailable()){
        //准备数据缓冲区
        QByteArray buffer;
        buffer.resize(tcpSocket.bytesAvailable());
        //读取消息
        //data():QByteArray-->char*
        tcpSocket.read(buffer.data(),buffer.size());
        //消息显示到界面
        ui->listWidget->addItem(buffer);
    }
}
