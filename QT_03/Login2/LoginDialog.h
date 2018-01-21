#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
public slots:
    void onAccepted(void);
    void onRejected(void);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
