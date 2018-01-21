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

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
public:
    const QString& getUserName();
    const QString& getPasswd();
private:
    Ui::LoginDialog *ui;
    QString username;
    QString passwd;
};

#endif // LOGINDIALOG_H
