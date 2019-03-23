#include "ShapeWidget.h"
#include <QDebug>

ShapeWidget::ShapeWidget(const QString& path,QDialog *parent)
    :QDialog(parent),m_picPath(path)
{

    QPixmap pix(m_picPath);//新建QPixmap对象
    //qDebug()<<"shapeWidget"<<m_picPath;
    //加载图片，设置图片防抖动
    //"photo.png",m_picPath
    //pix.load(m_picPath,0,
    //         Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
    if(pix.width()>900||pix.height()>700){
        float_t ratio=pix.width()/pix.height();
        float_t height_t=500*ratio;
        pix=pix.scaled(500,(int)height_t);
    }
    qDebug()<<pix.size();
    resize(pix.size());//使控件大小等于图片大小
    setMask(QBitmap(pix.mask()));//加掩码，使空白部分看起来透明
}

ShapeWidget::~ShapeWidget(void)
{
    qDebug()<<"ShapeWidget::~ShapeWidget";
}

void ShapeWidget::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton){
        m_dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton){
        close();
        deleteLater();
    }
}

void ShapeWidget::mouseMoveEvent(QMouseEvent* event)
{
    move(event->globalPos()-m_dragPosition);
    event->accept();
}

void ShapeWidget::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);
    QPixmap pix=QPixmap(m_picPath);
    if(pix.width()>900||pix.height()>700){
        float_t ratio=pix.width()/pix.height();
        float_t height_t=500*ratio;
        pix=pix.scaled(500,(int)height_t);
    }
    qDebug()<<pix.size();
    painter.drawPixmap(0,0,pix);//"photo.png",m_picPath

    /*
    //绘制shapeWidget界面背景图
    //1）创建画家对象
    QPainter painter(this);//device是QWidget时，绘图操作只能通过paintEvent().
    //2）获取要获取的矩形区域
    QRect rcImage=this->rect();
    //平移rcImage坐标让其和painter使用相同坐标
    rcImage.translate(this->geometry().topLeft());
    //3）准备要绘制的图片对象
    //eg:iamge/*.jpg
    QImage image("/root/Desktop/CSDN/QT/基本对话框/BaseDialog/16.png");
    //4）将准备好的图片image绘制到指定矩形区域
    painter.drawImage(rcImage,image);
    */

}
