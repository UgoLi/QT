#ifndef TCPSERVERDIALOG_H
#define TCPSERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TcpServerDialog;
}

class TcpServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServerDialog(QWidget *parent = 0);
    ~TcpServerDialog();

private slots:
    //创建服务器槽函数
    void on_pushButton_clicked();
    //处理和客户端连接
    void onNewConnection();
    //接受客户聊天消息
    void onReadyRead();
private:
    //转发聊天消息给所有客户端
    void sendMessage(QByteArray &msg);

private:
    Ui::TcpServerDialog *ui;
    QTcpServer tcpSever;
    qint16 port;
    //定义容器，用于保存所有和客户端通信的套接字
    QList<QTcpSocket*> tcpClientList;
};

#endif // TCPSERVERDIALOG_H
