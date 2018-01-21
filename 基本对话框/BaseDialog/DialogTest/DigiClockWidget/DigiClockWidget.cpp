#include "DigiClockWidget.h"

DigiClockWidget::DigiClockWidget(QWidget *parent)
    :QLCDNumber(parent)
{
    /*设置时钟背景*/
    QPalette p=palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);//设置窗口类型，无面板无标题栏
    setWindowOpacity(0.5);//设置窗口透明度
    QTimer *timer=new QTimer(this);//创建定时器对象
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);//间隔1000ms
    showTime();
    resize(400,240);
    setMinimumSize(150,90);
    move(760,420);
    m_showColon=true;
}

void DigiClockWidget::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton){
        m_dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton){
        close();
    }
}
DigiClockWidget::~DigiClockWidget(void)
{
    qDebug()<<"DigiClockWidget::~DigiClockWidget";
}

void DigiClockWidget::mouseMoveEvent(QMouseEvent* event)
{
    move(event->globalPos()-m_dragPosition);
    event->accept();
}

void DigiClockWidget::showTime()
{
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm");
    if(m_showColon){
        text[2]=':';
        m_showColon=false;
    }
    else{
        text[2]=' ';
        m_showColon=true;
    }
    display(text);
}
