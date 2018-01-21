#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public:
    //获取界面用户和密码
    QString getUsername(void)const;
    QString getPasswd(void)const;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
