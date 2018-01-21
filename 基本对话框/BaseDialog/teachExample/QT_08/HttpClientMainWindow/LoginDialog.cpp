#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
    qDebug()<<"LoginDialog::~LoginDialog";
}

void LoginDialog::on_buttonBox_accepted()
{
    accept();
}

void LoginDialog::on_buttonBox_rejected()
{
    reject();
}

//获取界面用户和密码
QString LoginDialog::getUsername(void) const
{
    return ui->usernameEdit->text();
}

QString LoginDialog::getPasswd(void) const
{
    return ui->passwdEdit->text();
}
