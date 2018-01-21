#include "LoginDialog.h"
#include "ui_LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
//ok按钮对应槽函数
void LoginDialog::on_buttonBox_accepted()
{
    //获取用户输入用户名和密码
    username = ui->m_username->text();
    passwd = ui->m_password->text();
    //退出登录对话框
    accept();//返回1
}
//cancel按钮对应槽函数
void LoginDialog::on_buttonBox_rejected()
{
    //退出登录对话框
    reject();//返回0
}
const QString& LoginDialog::getUserName()
{
    return username;
}
const QString& LoginDialog::getPasswd()
{
    return passwd;
}



