#ifndef STDMSGDIALOG_H
#define STDMSGDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class StdMsgDialog;
}

class StdMsgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StdMsgDialog(QWidget *parent = 0);
    ~StdMsgDialog();

private slots:
    void on_m_questionButton_clicked();

    void on_m_warningButton_clicked();

    void on_m_aboutButton_clicked();

    void on_m_infoButton_clicked();

    void on_m_criticalButton_clicked();

    void on_m_aboutQtButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::StdMsgDialog *ui;
};

#endif // STDMSGDIALOG_H
