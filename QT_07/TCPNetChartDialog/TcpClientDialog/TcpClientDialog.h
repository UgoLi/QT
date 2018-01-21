#ifndef TCPCLIENTDIALOG_H
#define TCPCLIENTDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

namespace Ui {
class TcpClientDialog;
}

class TcpClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClientDialog(QWidget *parent = 0);
    ~TcpClientDialog();

private slots:
    //连接服务器槽函数
    void on_connectButton_clicked();
    //发送按钮槽函数
    void on_sendButton_clicked();

    //与服务器连接时被执行
    void onConnected(void);
    //与服务器连接时被执行
    void onDisconnected(void);
    //网络异常时被执行
    void onError(QAbstractSocket::SocketError);
    //收到服务器的消息时
    void onReadyread(void);

private:
    Ui::TcpClientDialog *ui;
    bool status;//标记客户端状态，true表示在线，false表示离线
    QTcpSocket tcpSocket;
    QHostAddress serverIp;//服务器IP
    qint16 serverPort;//服务器端口
    QString username;//聊天昵称
};

#endif // TCPCLIENTDIALOG_H
