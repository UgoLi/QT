#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QDebug>
#include <QAbstractButton>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    connect(ui->m_btnBox,SIGNAL(accepted()),this,SLOT(onAccepted()));
    connect(ui->m_btnBox,SIGNAL(rejected()),this,SLOT(onRejected()));

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onAccepted(){
    if(ui->m_username->text()=="tarena" &&
            ui->m_password->text()=="123456"){
        QMessageBox msg(
                    QMessageBox::Information,
                    "Information",
                    "登陆成功！欢迎进入...",
                    QMessageBox::NoButton,//Close|QMessageBox::Cancel,
                    this);
        void* btnclose =
            msg.addButton("关闭程序",QMessageBox::YesRole);
        msg.addButton("退出登陆",QMessageBox::NoRole);
        msg.exec();
        if(msg.clickedButton()==btnclose)
            close();
    }else {
        QMessageBox msg(
                    QMessageBox::Warning,
                    "Warning",
                    "用户或密码错误",
                    QMessageBox::Retry,
                    this);
        msg.exec();
    }
}

void LoginDialog::onRejected(){
    QMessageBox msg(
                QMessageBox::Question,
                "Question",
                "是否退出登陆？",
                QMessageBox::No|QMessageBox::Yes,
                this);

    if(msg.exec()==QMessageBox::Yes)
        close();
}











