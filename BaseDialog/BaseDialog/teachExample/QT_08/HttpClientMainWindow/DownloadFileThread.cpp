#include "DownloadFileThread.h"

DownloadFileThread::DownloadFileThread(
  const QUrl* fileUrl,QNetworkAccessManager* manager,QObject *parent)
      :fileUrl(new QUrl(fileUrl->toString())),manager(manager),QObject(parent)
{
    qDebug()<<"创建下载线程...";
    //fileUrl=new QUrl("http://code.tarena.com.cn/CSDCode/csd1706/QT/day02.zip");
    file=new QFile(QFileInfo(fileUrl->path()).fileName(),
                     this);
    file->open(QIODevice::WriteOnly);

    //manager=new QNetworkAccessManager();

    request=new QNetworkRequest(*fileUrl);
    reply=manager->get(*request);

    //处理服务器回应信号 readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(receiveFile()));

    //处理服务器回应信号 finished
    connect(reply,SIGNAL(finished()),
            this,SLOT(receiveFileFinished()));

}
DownloadFileThread::~DownloadFileThread()
{
    qDebug()<<"DownloadFileThread::~DownloadFileThread";
}

void DownloadFileThread::receiveFile()
{
    emit isDownloading(QString("%1").asprintf("%p",QThread::currentThreadId()));//发送信号
    qDebug()<<"正在下载文件:"<<file->fileName();
    qDebug()<<"current threadId:"<<QThread::currentThreadId();
    //读取响应数据同时写到对应文件中
    file->write(reply->readAll());
    qDebug()<<"...";
}

//接收文件结束槽函数
void DownloadFileThread::receiveFileFinished()
{
    emit isFinished();//下载完成,发送信号给界面
    qDebug()<<"文件下载完成...";
    //刷新文件缓冲区
    file->flush();
    //关闭文件的操作
    file->close();
    //删除reply对象
    reply->deleteLater();
    //删除线程
    deleteLater();
}
