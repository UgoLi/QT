#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QAuthenticator>
#include <QProgressDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include "LoginDialog.h"
#include "DownloadFileThread.h"
#include "showDownloadProgressDialog.h"


namespace Ui {
class HttpClientMainWindow;
}

class HttpClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HttpClientMainWindow(QWidget *parent = 0);
    ~HttpClientMainWindow();
public:
    //向服务器发送其请求
    void sendRequest(void);
private slots:
    //处理登陆验证
    void onAuthenticationRequired(QNetworkReply*,QAuthenticator*);
    //接受响应数据的槽函数
    void onReadyRead(void);
    //数据接收完成时对应的槽函数
    void onFinished(void);

    //处理链接
    void onAchorClicked(const QUrl &url);

private slots:
    //url内容改变槽函数
    void on_lineEdit_returnPressed();

protected:
    void closeEvent(QCloseEvent* event);


private:
    Ui::HttpClientMainWindow *ui;
    QNetworkAccessManager* manager;
    QNetworkRequest* request;
    QNetworkReply* reply;

    QUrl currentUrl;//保存当前的网址

    QFile* file;//保存的文件

    //定义容器，保存所有支持下载的文件类型
    QList <QString> fileTpye;

    QProgressDialog* progressDialog;

    //线程后台处理数据的对象,前台显示处理界面
    DownloadFileThread* downloadThread;
    showDownloadProgressDialog* showDownloadProgress;
};

#endif // MAINWINDOW_H
