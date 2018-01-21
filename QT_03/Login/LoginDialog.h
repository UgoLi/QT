/*************************************************************************
	> File Name: LoginDialog.h
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 14时24分19秒
 ************************************************************************/

#ifndef _LOGINDIALOG_H
#define _LOGINDIALOG_H
#include<QDialog>
#include<QMessageBox>

#include"ui_LoginDialog.h"

class LoginDialog:public QDialog,public Ui::LoginDialog{
    Q_OBJECT
public:
    LoginDialog(void);
private slots:
    //处理OK按钮
    void onAccepted(void);
    //处理Cancel按钮
    void onRejected(void);
};



#endif//_LOGINDIALOG_H
