/*************************************************************************
	> File Name: CalculatorDialog.h
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 16时14分49秒
 ************************************************************************/

#ifndef _CALCULATORDIALOG_H
#define _CALCULATORDIALOG_H

#include<QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QLabel>
#include<QComboBox>

#include<QHBoxLayout>//水平布局器
#include<QDoubleValidator>//()双精度浮点验证器

//当前类是QDialog子类，继承父窗体的功能
class CalculatorDialog:public QDialog{
    Q_OBJECT
public:
    CalculatorDialog();
public slots:
    //使能等号按钮
    void enabeleCalcButton(void);
    //计算和显示结果
    void calcClicked(void);
private:
    QLineEdit* m_editx;//做操作数
    QLineEdit* m_edity;//右操作数
    QComboBox* m_symbol;//操作符
    QPushButton* m_btnCalc;//加号按钮
    QLineEdit* m_editZ;//保存结果
};
#endif//_CALCULATORDIALOG_H
