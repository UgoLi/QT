#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>

namespace Ui {
class CalculatorDialog;
}

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorDialog(QWidget *parent = 0);
    ~CalculatorDialog();
public slots:
    void enabledCalcButton(void);//检测左右操作数，满足，显示计算按钮
    void calcClicked(void);//接受计算按钮信号的槽函数

private:
    Ui::CalculatorDialog *ui;
};

#endif // CALCULATORDIALOG_H
