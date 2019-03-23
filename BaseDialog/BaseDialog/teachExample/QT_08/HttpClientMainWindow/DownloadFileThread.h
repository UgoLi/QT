#ifndef DOWNLOADFILETHREAD_H
#define DOWNLOADFILETHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

class DownloadFileThread : public QObject
{
    Q_OBJECT
public:
    explicit DownloadFileThread(
            const QUrl *fileUrl, QNetworkAccessManager *manager,QObject *parent = nullptr);
    ~DownloadFileThread();

private slots:
    //接收文件内容的槽函数
    void receiveFile();
    //接收文件结束槽函数
    void receiveFileFinished();

signals:
    void isDownloading(QString);//正在下载
    void isFinished();//已完成

public:
    QNetworkReply* reply;

private:
    QUrl* fileUrl;
    QNetworkAccessManager* manager;
    QNetworkRequest* request;
    QFile* file;
};

#endif // DOWNLOADFILETHREAD_H
