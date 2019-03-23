#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QDebug>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

private slots:
    void on_m_changeNameButton_clicked();

    void on_m_changeSexButton_clicked();

    void on_m_changeAgeButton_clicked();

    void on_m_changeScoreButton_clicked();

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
