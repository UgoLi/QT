#include "SemaphoreDialog.h"
#include "ui_SemaphoreDialog.h"
#include "QDebug"


SemaphoreDialog::SemaphoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemaphoreDialog)
{
    ui->setupUi(this);
    threadProducer::wareProgressBar=ui->wareProgressBar;
    threadConsumer::wareProgressBar=ui->wareProgressBar;

    threadProducer::productedProgressBar=ui->productedProgressBar;
    threadProducer::needProductProgressBar=ui->needProductProgressBar;

    threadConsumer::consumedProgressBar=ui->consumedProgressBar;

    connect(ui->wareTotalEdit,SIGNAL(textChanged(QString)),
            this,SLOT(onEditingFinished()));
}

SemaphoreDialog::~SemaphoreDialog()
{
    delete ui;
    qDebug()<<"SemaphoreDialog::~SemaphoreDialog";
}

//仓库总数改变槽函数
void SemaphoreDialog::onEditingFinished()
{
    DataSize=ui->wareTotalEdit->text().toInt();
    ui->productedProgressBar->setMaximum(DataSize);
    ui->consumedProgressBar->setMaximum(DataSize);
    ui->needProductProgressBar->setMaximum(DataSize);
    ui->needProductProgressBar->setValue(DataSize);
}

//生产开始槽函数
void SemaphoreDialog::on_pushButton_clicked()
{
    ui->productedProgressBar->setValue(0);
    ui->consumedProgressBar->setValue(0);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("正在生产...,等待操作完成");
    threadProducer producer;
    threadConsumer consumer;
    producer.productSpeed=ui->productSpeedEdit->text().toInt();
    consumer.consumSpeed=ui->consumSpeedEdit->text().toInt();

    producer.start();//生产开始
    consumer.start();//消费开始

    producer.wait();
    consumer.wait();

    ui->pushButton->setEnabled(true);
    ui->pushButton->setText("开始生产者和消费者");

    return;
}
