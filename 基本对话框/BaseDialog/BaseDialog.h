#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>
#include <QThread>
#include <QPaintEvent>
#include <QPainter>

#include "DialogTest/InputDialog/InputDialog.h"
#include "DialogTest/StdMsgDialog/StdMsgDialog.h"
#include "DialogTest/DrawerToolBoxDialog//DrawerToolBoxDialog.h"
#include "DialogTest/ProgressBarDialog/ProgressBarDialog.h"
#include "DialogTest/DigiClockWidget/DigiClockWidget.h"
#include "DialogTest/ShapeWidget/ShapeWidget.h"

#include "teachExample/QT_07/UdpBroadCastDialog/sendDialog/sendDialog.h"
#include "teachExample/QT_07/UdpBroadCastDialog/receiveDialog/receiveDialog.h"
#include "teachExample/QT_07/TCPNetChartDialog/TcpServerDialog/TcpServerDialog.h"
#include "teachExample/QT_07/TCPNetChartDialog/TcpClientDialog/TcpClientDialog.h"
#include "teachExample/QT_06/ThreadDialog/ThreadDialog.h"
#include "teachExample/QT_06/SemaphoreDialog/SemaphoreDialog.h"
#include "teachExample/QT_08/HttpClientMainWindow/HttpClientMainWindow.h"

namespace Ui {
class BaseDialog;
}

class BaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDialog(QWidget *parent = 0);
    ~BaseDialog();

protected:
    void paintEvent(QPaintEvent* event);

private slots:
    //文件选择事件处理
    void on_m_fileDialogButton_clicked();

    //颜色选择事件处理
    void on_m_colorDialogButton_clicked();

    //字体选择事件处理
    void on_m_fontDialogButton_clicked();

    //输入对话显示事件处理
    void on_m_inputButton_clicked();

    //提示消息对话事件处理
    void on_m_msgButton_clicked();

    //工具盒（QQ界面）显示事件处理
    void on_m_toolBoxButton_clicked();

    //进度条案例显示事件处理
    void on_m_progressButton_clicked();

    //颜色选择组合按钮事件处理
    void on_m_colorComboBox_activated(int index);

    //电子时钟案例显示事件处理
    void on_m_digiClockButton_clicked();

    //选择自定义控件形状外形图片事件处理
    void on_m_chooseFileButton_clicked();

    //创建并显示自定义控件
    void on_m_shapeWidgetButton_clicked();

    //udp广播案例显示
    void on_m_udpBroadCastButton_clicked();

    //tcp网络聊天案例显示
    void on_m_tcpNetCartButton_clicked();

    //多线程案例显示
    void on_m_threadButton_clicked();

    //信号量案例显示
    void on_m_SemphoreButton_clicked();

    //http客户端访问网路文件案例
    void on_m_httpClientButton_clicked();

private:
    Ui::BaseDialog *ui;
    DigiClockWidget* clock;//电子时钟

    //ShapeWidget* shapeWidget;//自定义外形控件

};

#endif // BASEDIALOG_H
