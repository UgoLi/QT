#include "ThreadDialog.h"
#include "ui_ThreadDialog.h"

ThreadDialog::ThreadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreadDialog)
{
    ui->setupUi(this);
}

ThreadDialog::~ThreadDialog()
{
    delete ui;
}

//开始线程
void ThreadDialog::on_startButton_clicked()
{
    threadA.start();
    threadB.start();
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

//停止线程
void ThreadDialog::on_stopButton_clicked()
{
    threadA.terminate();
    threadA.wait();
    threadB.terminate();
    threadB.wait();
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}
