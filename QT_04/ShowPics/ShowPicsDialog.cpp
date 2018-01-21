#include "ShowPicsDialog.h"
#include "ui_ShowPicsDialog.h"

ShowPicsDialog::ShowPicsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowPicsDialog)
{
    ui->setupUi(this);

    setMouseTracking(true);//设置鼠标未按下时移动，触发MouseMoveEvent事件


    //按钮透明
    //ui->m_prev->setFlat(false);
    //ui->m_next->setFlat(true);
    rcPrev=new QRect(mapFromParent(ui->m_prev->pos()),ui->m_prev->rect().size());
    //rcPrev=new QRect(ui->m_prev->pos(),ui->m_prev->size());
    //rcPrev->(ui->frame->pos());
    //qDebug()<<"rcPrec:"<<ui->m_prev->pos().x()<<','<<ui->m_prev->pos().y();
    qDebug()<<"rcPrev:"<<rcPrev->x()<<','<<rcPrev->y();
    rcNext=new QRect(ui->m_next->pos(),ui->m_next->size());
    //rcNext->translate(ui->m_next->pos());
    qDebug()<<"rcNext:"<<ui->m_next->pos().x()<<','<<ui->m_next->pos().y();

    //按钮隐藏
    ui->m_prev->setVisible(false);
    ui->m_next->setVisible(false);
}

ShowPicsDialog::~ShowPicsDialog()
{
    delete ui;
    m_idxImage=0;
}

void ShowPicsDialog::paintEvent(QPaintEvent*){
    //1）创建画家对象
    QPainter painter(this);//device是QWidget时，绘图操作只能通过paintEvent().
    //2）获取要获取的矩形区域
    QRect rcImage=ui->frame->frameRect();
    //平移rcImage坐标让其和painter使用相同坐标
    rcImage.translate(ui->frame->pos());

    //3）准备要绘制的图片对象
    //eg:iamge/*.jpg
    QImage image(":/images/"+QString::number(m_idxImage)+".jpg");
    //4）将准备好的图片image绘制到指定矩形区域
    painter.drawImage(rcImage,image);

    ui->m_prev->setStyleSheet("border-image: url(:/images/"+
        QString::number((m_idxImage-1)<0?9:(m_idxImage-1))+".jpg);");
    ui->m_next->setStyleSheet("border-image: url(:/images/"+
        QString::number((m_idxImage+1)>9?0:(m_idxImage+1))+".jpg);");
}



void ShowPicsDialog::on_m_btnPrev_clicked()
{
    if(--m_idxImage<0)
        m_idxImage=9;
    update();//触发绘图事件
}

void ShowPicsDialog::on_m_btnNext_clicked()
{
    if(++m_idxImage>9)
        m_idxImage=0;
    update();//触发绘图事件
}


void ShowPicsDialog::on_m_prev_clicked()
{
    if(--m_idxImage<0)
        m_idxImage=9;
    update();//触发绘图事件
}

void ShowPicsDialog::on_m_next_clicked()
{
    if(++m_idxImage>9)
        m_idxImage=0;
    update();//触发绘图事件

}

void ShowPicsDialog:: mouseMoveEvent(QMouseEvent* event)
{


    qDebug()<<"mousePos:"<<event->pos().x()<<','<<event->pos().y();
    if(rcPrev->contains(event->pos())){
        ui->m_prev->setVisible(true);
    }else{
        ui->m_prev->setVisible(false);
    }


    if(rcNext->contains(event->pos())){
        ui->m_next->setVisible(true);
    }else{
        ui->m_next->setVisible(false);
    }
}








