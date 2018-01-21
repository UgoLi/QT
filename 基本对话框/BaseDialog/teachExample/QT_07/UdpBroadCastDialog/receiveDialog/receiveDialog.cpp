#include "receiveDialog.h"
#include "ui_receiveDialog.h"

receiveDialog::receiveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiveDialog)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket;
    isStarted=false;

}

receiveDialog::~receiveDialog()
{
    delete ui;
    qDebug()<<"receiveDialog::~receiveDialog";
}

void receiveDialog::on_pushButton_clicked()
{
    if(isStarted==false){
        isStarted=true;
        port=ui->lineEdit->text().toShort();
        bool res=udpSocket->bind(port);
        if(res==false){
            QMessageBox::information(
                        this,"Error","绑定失败!");
            return;
        }
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setText("停止接收");
        connect(udpSocket,SIGNAL(readyRead()),this,SLOT(msgReceive()));
    }else {
        isStarted=false;
        ui->lineEdit->setEnabled(true);
        ui->pushButton->setText("开始接收");
        //关闭套接字
        udpSocket->close();
    }
}

//接受广播消息的槽函数
void receiveDialog::msgReceive(void)
{
    //判断当前套接字是否有数据包到来
    if(udpSocket->hasPendingDatagrams()){
        //接收的数据缓冲区
        QByteArray buffer;
        //获取数据包大小
        buffer.resize(udpSocket->pendingDatagramSize());
        //读数据包
        //data():QByteArray->char*
        udpSocket->readDatagram(buffer.data(),buffer.size());
        //显示消息到UI
        ui->listWidget->addItem(buffer);
    }
}
