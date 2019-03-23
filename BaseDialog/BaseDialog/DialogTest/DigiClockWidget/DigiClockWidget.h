#ifndef DIGICLOCKWIDGET_H
#define DIGICLOCKWIDGET_H

#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

class DigiClockWidget:public QLCDNumber
{
    Q_OBJECT
public:
    DigiClockWidget(QWidget* parent=0);
    ~DigiClockWidget(void);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
public slots:
    void showTime();//显示当前时间
private:
    QPoint m_dragPosition;//鼠标相对电子时钟框体左上角的偏移量
    bool m_showColon;//是否显示“:”
};

#endif // DIGICLOCKWIDGET_H
