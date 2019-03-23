#include "BaseDialog.h"
#include "ui_BaseDialog.h"


//ComboBox背景色设置
void static showComboBoxColor(QComboBox* m_colorComboBox){
    QStringList colorList=QColor::colorNames();
    QString color;
    foreach (color, colorList) {
        QPixmap pix(QSize(m_colorComboBox->size()));
        pix.fill(QColor(color));
        m_colorComboBox->addItem((QIcon(pix)),color);
        m_colorComboBox->setIconSize(m_colorComboBox->size());
        m_colorComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

BaseDialog::BaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QPixmap("../BaseDialog/startImage/Icon.png")));


    clock=new DigiClockWidget;//创建电子时钟控件

    showComboBoxColor(ui->m_colorComboBox);


    QThread::sleep(3);
}


BaseDialog::~BaseDialog()
{
    delete ui;
    delete clock;
    //delete shapeWidget;
    qDebug()<<"析构";
}

//背景设置
void BaseDialog::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),
                       QPixmap("../BaseDialog/startImage/background.jpg"));
}


//标准文件选择
QString lastPath="/";
void BaseDialog::on_m_fileDialogButton_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,"open file dialog",lastPath);
    if(filePath!=""){
        lastPath=filePath;
        ui->m_fileShow->setText(filePath);
    }
}

//标准颜色选择
void BaseDialog::on_m_colorDialogButton_clicked()
{
    QColor color=QColorDialog::getColor();
    if(color.isValid()){
        ui->m_colorFrame->setPalette(color);
    }
}

//标准字体选择
void BaseDialog::on_m_fontDialogButton_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok);
    if(ok){
        ui->m_fontShow->setFont(font);
    }
}

//输入提示框
void BaseDialog::on_m_inputButton_clicked()
{
    InputDialog inputDialog(this);
    inputDialog.show();
    inputDialog.exec();
}

//消息提示框
void BaseDialog::on_m_msgButton_clicked()
{
    StdMsgDialog stdMsgDialog(this);
    stdMsgDialog.show();
    stdMsgDialog.exec();
}

//工具盒窗体
void BaseDialog::on_m_toolBoxButton_clicked()
{
    QDialog toolBoxDialog;
    DrawerToolBoxDialog drawerToolBox(&toolBoxDialog);
    toolBoxDialog.setMaximumSize(drawerToolBox.maximumSize());
    toolBoxDialog.setMinimumSize(drawerToolBox.minimumSize());
    drawerToolBox.show();
    toolBoxDialog.exec();
}

//进度条窗体
void BaseDialog::on_m_progressButton_clicked()
{
    ProgressBarDialog progressBarDialog;
    progressBarDialog.show();
    progressBarDialog.exec();
}

//自定义ComboBox颜色选择
void BaseDialog::on_m_colorComboBox_activated(int index)
{
    QStringList colorList=QColor::colorNames();
    QColor color=colorList[index/*ui->m_colorComboBox->currentIndex()*/];
    QPalette p=ui->m_colorFrame_2->palette();
    p.setColor(QPalette::Window,color);
    //更新frame设置
    ui->m_colorFrame_2->setPalette(p);
    ui->m_colorFrame_2->update();
}

//电子风格显示（简单电子表）
void BaseDialog::on_m_digiClockButton_clicked()
{
    clock->show();
}

//自定义控件外形图片选择
QString lastPicPath="/";
void BaseDialog::on_m_chooseFileButton_clicked()
{
    lastPicPath=ui->m_picPathEdit->text();
    QString filePath=QFileDialog::getOpenFileName(this,"选择一张图片",lastPicPath);
    if(filePath!=""){
        lastPicPath=filePath;
        ui->m_picPathEdit->setText(filePath);
    }
}

//生成自定义外形控件
void BaseDialog::on_m_shapeWidgetButton_clicked()
{
    ShapeWidget* shapeWidget=new ShapeWidget(
                ui->m_picPathEdit->text(),this);//创建自定义外形窗体
    //qDebug()<<shapeWidget->m_picPath;
    shapeWidget->show();
    //shapeWidget->exec();
}

//显示Udp广播对话窗
void BaseDialog::on_m_udpBroadCastButton_clicked()
{
    sendDialog send(this);
    receiveDialog recv1(this);
    receiveDialog recv2(this);

    send.show();
    recv1.show();
    recv2.show();
    recv1.move(send.geometry().topLeft().x()-recv1.size().width(),
               send.geometry().topRight().y());
    recv2.move(send.geometry().topRight());

    send.exec();
}

//显示TCP聊天室服务器
void BaseDialog::on_m_tcpNetCartButton_clicked()
{
    TcpServerDialog tcpSever(this);

    TcpClientDialog tcpClient1;
    tcpClient1.setWindowFlags(Qt::FramelessWindowHint);//设置窗口类型，无面板无标题栏
    TcpClientDialog tcpClient2;
    tcpClient2.setWindowFlags(Qt::CustomizeWindowHint);//设置窗口类型，无面板无标题栏

    tcpSever.show();
    tcpClient1.show();
    tcpClient2.show();
    tcpClient1.move(tcpSever.geometry().topLeft().x()-tcpClient1.size().width(),
               tcpSever.geometry().topRight().y());
    tcpClient2.move(tcpSever.geometry().topRight());

    tcpSever.exec();
}


//多线程案例显示
void BaseDialog::on_m_threadButton_clicked()
{
    ThreadDialog threadDialog(this);

    threadDialog.show();
    threadDialog.exec();
}

//信号量案例显示
void BaseDialog::on_m_SemphoreButton_clicked()
{
    SemaphoreDialog semDialog(this);
    semDialog.show();
    semDialog.exec();
}

//http客户端访问网路文件案例
void BaseDialog::on_m_httpClientButton_clicked()
{
    HttpClientMainWindow* httpwindow=new HttpClientMainWindow(this);//创建httpClient界面
    httpwindow->showMaximized();
    httpwindow->setFocus();
    hide();
    QEventLoop loop;
    loop.exec();
}
