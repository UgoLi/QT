#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QAuthenticator>//登录验证

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    //向服务器发送其请求
    void sendRequest(void);
private slots:
    //处理菜单选项的槽函数
    void onTriggred(QAction*);
    //处理登录验证
    void onAuthenticationRequired(
            QNetworkReply*,QAuthenticator*);

    //界面刷新槽函数
    void onTextChanged(QString);

    //接收响应数据的槽函数
    void onReadyRead(void);
    //接收响应数据完成对应槽函数
    void onFinished(void);
    //处理链接
    void onAnchorClicked(const QUrl&);
private:
    //下载文件
    void downloadFile(const QUrl&);
private slots:
    //接收文件内容的槽函数
    void receiveFile(void);
    //下载文件完成对应的槽函数
    void receiveFileFinished(void);

    //更新显示进度条槽函数
    void updateDownloadProgress(qint64,qint64);
    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

    //管理HTTP请求和响应
    QNetworkAccessManager* manager;
    QNetworkRequest* request;//请求
    QNetworkReply* reply;//响应

    QUrl currentUrl;//保存当前网址
    //定义容器，保存所有支持下载的文件类型
    QList <QString> fileTpye;

    QFile* file;//保存要下载文件
};

#endif // MAINWINDOW_H







