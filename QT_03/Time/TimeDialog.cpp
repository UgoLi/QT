/*************************************************************************
	> File Name: TimeDialog.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 09时22分21秒
 ************************************************************************/

//界面初始化，信号和槽连接
#include"TimeDialog.h"

TimeDialog::TimeDialog(void){
    //设置系统时间
    setWindowTitle("系统时间");
    m_labTime=new QLabel(this);
    m_btnTime=new QPushButton("获取系统当前时间",this);
    //设置label边框效果:凹陷的效果
    m_labTime->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //设置label文本居中
    m_labTime->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //创建垂直布局器
    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->addWidget(m_labTime);
    layout->addWidget(m_btnTime);
    setLayout(layout);

    //信号和槽连接
    connect(m_btnTime,SIGNAL(clicked()),this,SLOT(timeClicked()));
}


//获取系统时间槽函数
void TimeDialog::timeClicked(void){
    QString res=
        QTime::currentTime().toString("hh:mm:ss");
    m_labTime->setText(res);

}


