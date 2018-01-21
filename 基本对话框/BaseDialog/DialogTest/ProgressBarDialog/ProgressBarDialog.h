#ifndef PROGRESSBARDIALOG_H
#define PROGRESSBARDIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include <QThread>
#include <QDebug>

namespace Ui {
class ProgressBarDialog;
}

class ProgressBarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressBarDialog(QWidget *parent = 0);
    ~ProgressBarDialog();

private slots:
    void on_m_startButton_clicked();

private:
    Ui::ProgressBarDialog *ui;
};

#endif // PROGRESSBARDIALOG_H
