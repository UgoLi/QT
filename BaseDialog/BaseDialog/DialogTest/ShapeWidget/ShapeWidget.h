#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include <QBitmap>
#include <QPaintEvent>
#include <QPainter>
#include <QDialog>
#include <QDebug>
#include <QPushButton>

class ShapeWidget:public QDialog
{
    Q_OBJECT
public:
    ShapeWidget(const QString& path,QDialog *parent=0);
    ~ShapeWidget(void);
    QString m_picPath;//图片路径
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
private:

    QPoint m_dragPosition;//鼠标、控件在屏幕的相对位置
};

#endif // SHAPEWIDGET_H
