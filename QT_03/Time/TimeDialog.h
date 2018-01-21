/*************************************************************************
	> File Name: TimeDialog.h
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 09时22分01秒
 ************************************************************************/

#ifndef _TIMEDIALOG_H
#define _TIMEDIALOG_H

#include<QDialog>
#include<QPushButton>
#include<QLabel>
#include<QTime>//时间
#include<QVBoxLayout>//垂直布局器

class TimeDialog:public QDialog{
    Q_OBJECT
public:
    TimeDialog(void);
private slots:
    //获取系统时间按钮对应的槽函数
    void timeClicked(void);
private:
    QLabel* m_labTime;
    QPushButton* m_btnTime;
};


#endif //_TIMEDIALOG_H
