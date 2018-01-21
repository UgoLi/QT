#ifndef RECEIVEDIALOG_H
#define RECEIVEDIALOG_H

#include <QDialog>
#include <QUdpSocket>
#include <QMessageBox>


namespace Ui {
class receiveDialog;
}

class receiveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit receiveDialog(QWidget *parent = 0);
    ~receiveDialog();

private slots:
    //开始接收按钮的槽函数
    void on_pushButton_clicked();
    //接受消息的槽函数
    void msgReceive(void);

private:
    QUdpSocket* udpSocket;
    quint16 port;
    bool isStarted;//记录标记，开始/停止

private:
    Ui::receiveDialog *ui;
};

#endif // RECEIVEDIALOG_H
