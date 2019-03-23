#include "TcpServerDialog.h"
#include "ui_TcpServerDialog.h"

TcpServerDialog::TcpServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServerDialog)
{
    ui->setupUi(this);
    //当有客户端连接时发送NewConnection信号
    connect(&tcpSever,SIGNAL(newConnection()),
            this,SLOT(onNewConnection()));
}

TcpServerDialog::~TcpServerDialog()
{
    delete ui;
    qDebug()<<"TcpServerDialog::~TcpServerDialog";
}

void TcpServerDialog::on_pushButton_clicked()
{
    //获取服务器端口号
    port=ui->lineEdit->text().toShort();
    //开启服务器
    if(tcpSever.listen(QHostAddress::Any,port)){
        qDebug("TCP 服务器创建成功!");
    }else {
        qDebug("TCP 服务器创建失败!");
        return;
    }
    //禁用创建服务器按钮和端口输入组件
    ui->pushButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

//处理和客户端连接
void TcpServerDialog::onNewConnection()
{
    //获取和客户端通信的套接字
    QTcpSocket* tcpClientSocket=
            tcpSever.nextPendingConnection();
    //保存套接字到容器
    tcpClientList.append(tcpClientSocket);
    //客户端给服务器发送消息时，对应套接字发送readyRead信号
    connect(tcpClientSocket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
}

//接受客户聊天消息
void TcpServerDialog::onReadyRead()
{
    for(int i=0;i<tcpClientList.count();i++){
        //检测当前套接字是否有效，如果已经断开连接，则将其从容器删除
        if(tcpClientList.at(i)->state()==QAbstractSocket::UnconnectedState){
            tcpClientList.removeAt(i);
            continue;
        }
        //bytesAvailable()，获取当前套接字等待读的数据个数
        if(tcpClientList.at(i)->bytesAvailable()){
            QByteArray readBuf=tcpClientList.at(i)->readAll();
            //显示界面到UI
            ui->listWidget->addItem(readBuf);
            //转发消息给所有客户端
            sendMessage(readBuf);
        }
    }
}

//转发聊天消息给所有客户端
void TcpServerDialog::sendMessage(QByteArray& msg)
{
    for(int i=0;i<tcpClientList.count();i++){
        tcpClientList.at(i)->write(msg);
    }
}
