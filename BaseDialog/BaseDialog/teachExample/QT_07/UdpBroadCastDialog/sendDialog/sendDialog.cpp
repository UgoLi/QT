#include "sendDialog.h"
#include "ui_sendDialog.h"

sendDialog::sendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendDialog)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    timer=new QTimer(this);
    //当定时器到时后，timer将发送timeout信号
    connect(timer,SIGNAL(timeout()),this,SLOT(sendMsg()));
    isStarted=false;
}

sendDialog::~sendDialog()
{
    delete ui;
    qDebug()<<"sendDialog::~sendDialog";
}

void sendDialog::on_startButton_clicked()
{
    if(isStarted==false){
        //开始广播
        isStarted=true;
        ui->startButton->setText("停止广播");
        timer->start(1000);//开始
        ui->portEdit->setEnabled(false);
        ui->msgEdit->setEnabled(false);
    }else{
        //停止广播
        isStarted=false;
        ui->startButton->setText("开始广播");
        timer->stop();//关闭
        ui->portEdit->setEnabled(true);
        ui->msgEdit->setEnabled(true);
    }
}

void sendDialog::sendMsg(void)
{
    //获取端口
    quint64 port=ui->portEdit->text().toShort();
    //获取广播内容
    QString msg=ui->msgEdit->text();
    //toLocal8Bit:QString->QByteArray
    udpSocket->writeDatagram(msg.toLocal8Bit(),
            QHostAddress::Broadcast,port);
}
