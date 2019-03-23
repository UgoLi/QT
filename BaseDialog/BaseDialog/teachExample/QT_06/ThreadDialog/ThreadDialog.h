#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>
#include "WorkerThread.h"

namespace Ui {
class ThreadDialog;
}

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThreadDialog(QWidget *parent = 0);
    ~ThreadDialog();

private slots:
    //开始线程
    void on_startButton_clicked();
    //停止线程
    void on_stopButton_clicked();

private:
    Ui::ThreadDialog *ui;
    WorkerThread threadA;
    WorkerThread threadB;
};

#endif // THREADDIALOG_H
