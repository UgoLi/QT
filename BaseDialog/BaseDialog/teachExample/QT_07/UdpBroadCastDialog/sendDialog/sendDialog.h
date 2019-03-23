#ifndef SENDDIALOG_H
#define SENDDIALOG_H

#include <QDialog>
#include <QHostAddress>
#include <QUdpSocket>
#include <QTimer>//定时器类

namespace Ui {
class sendDialog;
}

class sendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sendDialog(QWidget *parent = 0);
    ~sendDialog();
private slots:
    void sendMsg(void);

    void on_startButton_clicked();

private:
    QUdpSocket* udpSocket;
    QTimer* timer;
    bool isStarted;//记录开始/停止广播
private:
    Ui::sendDialog *ui;
};

#endif // SENDDIALOG_H
