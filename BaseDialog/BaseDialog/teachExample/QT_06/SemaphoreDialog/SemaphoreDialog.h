#ifndef SEMAPHOREDIALOG_H
#define SEMAPHOREDIALOG_H

#include <QDialog>
#include "Semaphore.h"

extern int DataSize;

namespace Ui {
class SemaphoreDialog;
}

class SemaphoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SemaphoreDialog(QWidget *parent = 0);
    ~SemaphoreDialog();

private slots:
    //仓库总数改变槽函数
    void onEditingFinished();

    //生产开始槽函数
    void on_pushButton_clicked();

private:
    Ui::SemaphoreDialog *ui;
};

#endif // SEMAPHOREDIALOG_H
