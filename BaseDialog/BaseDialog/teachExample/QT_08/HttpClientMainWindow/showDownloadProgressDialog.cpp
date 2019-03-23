#include "showDownloadProgressDialog.h"
#include "ui_showDownloadProgressDialog.h"

showDownloadProgressDialog::showDownloadProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showDownloadProgressDialog)
{
    ui->setupUi(this);
}

showDownloadProgressDialog::~showDownloadProgressDialog()
{
    delete ui;
}

//处理进度条信号
void showDownloadProgressDialog::updateDownloadProgress(qint64 size, qint64 allSize)
{
    //qDebug()<<"update Progress"<<size<<","<<allSize;

    ui->progressBar->setMaximum(allSize);
    ui->progressBar->setValue(size);

    //qDebug()<<"...";
}

//处理isDownloading信号
void showDownloadProgressDialog::onIsDownloading(QString const& threadId){
    ui->threadIdEdit->setText(threadId);
    ui->closeButton->setEnabled(false);
    ui->cancelButton->setEnabled(true);
    ui->statusEdit->setText("Downloading...");
}

//处理完成信号
void showDownloadProgressDialog::onIsFinished(void){
    ui->closeButton->setEnabled(true);
    ui->cancelButton->setEnabled(false);
    ui->showInDirButton->setEnabled(true);
    ui->statusEdit->setText("Completed");
}

void showDownloadProgressDialog::closeEvent(QCloseEvent* event){
    event->ignore();
}

void showDownloadProgressDialog::
setUiInfo(QString const& filename,QString const& downThreadId){
    ui->fileNameEdit->setText(filename);
    ui->uiTthreadIdEdit->setText(downThreadId);
}

void showDownloadProgressDialog::on_closeButton_clicked()
{
    deleteLater();
}

void showDownloadProgressDialog::on_showInDirButton_clicked()
{
    QDesktopServices::openUrl(QUrl("./"));
}
