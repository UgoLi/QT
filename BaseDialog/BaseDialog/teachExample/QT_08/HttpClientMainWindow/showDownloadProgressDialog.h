#ifndef SHOWDOWNLOADPROGRESSDIALOG_H
#define SHOWDOWNLOADPROGRESSDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class showDownloadProgressDialog;
}

class showDownloadProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showDownloadProgressDialog(QWidget *parent = 0);
    ~showDownloadProgressDialog();

public slots://界面刷新槽函数
    //处理进度条信号
    void updateDownloadProgress(qint64 size, qint64 allSize);
    //处理isDownloading信号
    void onIsDownloading(QString const&);
    //处理完成信号
    void onIsFinished(void);

private:
    void closeEvent(QCloseEvent* event);

public:
    void setUiInfo(QString const& filename,QString const& downThreadId);
private slots:
    void on_closeButton_clicked();

    void on_showInDirButton_clicked();

private:
    Ui::showDownloadProgressDialog *ui;
};

#endif // SHOWDOWNLOADPROGRESSDIALOG_H
