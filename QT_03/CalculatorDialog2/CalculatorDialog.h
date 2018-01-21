#ifndef __CALCULATORDIALOG_H
#define __CALCULATORDIALOG_H

#include <QDialog>
#include <QLineEdit>//输入组件
#include <QPushButton>
#include <QLabel>

#include <QHBoxLayout>//水平布局器
#include <QDoubleValidator>//验证器
#include "ui_CalculatorDialog.h"


//当前类是QDialog子类，继承父窗口的功能
//从界面类中继承和界面相关的代码
class CalculatorDialog
    :public QDialog,public Ui::CalculatorDialog{
    Q_OBJECT
public:
    CalculatorDialog(void);
public slots:
    //使能等号按钮
    void enableCalcButton(void);
    //计算和显示结果
    void calcClicked(void);
/*private:
    QLineEdit* m_editX;//左操作数
    QLineEdit* m_editY;//右操作数
    QPushButton* m_btnCalc;//加号按钮
    QLineEdit* m_editZ;//保存结果
*/
};

#endif//__CALCULATORDIALOG_H






