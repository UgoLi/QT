#include "MouseDialog.h"
#include "ui_MouseDialog.h"

MouseDialog::MouseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseDialog)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

MouseDialog::~MouseDialog()
{
    delete ui;
}

//鼠标按下event
/*
void MouseDialog:: mousePressEvent(QMouseEvent* event)
{
    //判断为鼠标左键
    if(event->button()==Qt::LeftButton){
        //获取矩形区域
        QRect rcBlock=ui->label->frameRect();
        //平移：rcBlock和鼠标使用相同坐标系
        rcBlock.translate(ui->label->pos());
        //判断鼠标的点击位置是否在rcBlock范围之类
        if(rcBlock.contains(event->pos())==true){
            m_bDrag=true;
            //记录鼠标和label相对位置
            m_ptPos=ui->label->pos()-event->pos();
        }
    }
}

//鼠标抬起
void MouseDialog:: mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton){
        m_bDrag=false;
    }
}
*/

//鼠标移动
void MouseDialog:: mouseMoveEvent(QMouseEvent* event)
{
    qDebug()<<"cursor:"<<event->pos().x()<<','<<event->pos().y();
    //if(m_bDrag){
        //计算label要移动的新位置：鼠标当前位置+相对位置
        m_ptPos=ui->label->pos()-event->pos();
    qDebug()<<"m_ptPos:"<<m_ptPos.x()<<','<<m_ptPos.y();
        QPoint ptPos=event->pos()+m_ptPos;
    qDebug()<<"ptPos:"<<ptPos.x()<<','<<ptPos.y();
        //设置label的移动范围
        //x坐标:0-(窗口宽-label宽)
        //y坐标:0-(窗口高-label高)
        //1)获取窗口和label大小
        QSize sz=size();
        QSize labeSz=ui->label->size();
        //2)x坐标:0-(窗口宽-label宽)
        if(ptPos.x()<0){
            ptPos.setX(0);
        }
        else if (ptPos.x()>sz.width()-labeSz.width()) {
            ptPos.setX(sz.width()-labeSz.width());
        }
        //3)y坐标:0-(窗口高-label高)
        if(ptPos.y()<0){
            ptPos.setY(0);
        }
        else if (ptPos.y()>sz.height()-labeSz.height()) {
            ptPos.setY(sz.height()-labeSz.height());
        }
        //移动label到指定位置
        ui->label->move(event->pos());
    //}
}
