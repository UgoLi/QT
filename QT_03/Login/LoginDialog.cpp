/*************************************************************************
	> File Name: LoginDialog.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 14时31分30秒
 ************************************************************************/

#include"LoginDialog.h"
#include<QDebug>

LoginDialog::LoginDialog(void){
    //界面初始化，载入Ui界面
    setupUi(this);
    
    //信号和槽连接
    //点击OK按钮发送accepted信号
    connect(m_btnBox,SIGNAL(accepted()),this,SLOT(onAccepted()));
    //点击Cancel发送Rejected信号
    connect(m_btnBox,SIGNAL(rejected()),this,SLOT(onRejected()));
}

void LoginDialog::onAccepted(void){
    //eg:tarenna 123456
    if(m_username->text()=="tarena" && m_password->text()=="123456"){
        //qDebug:打印调试函数，用法类似printf
        qDebug("登陆成功");
        qDebug()<<"Login Success";
        close();
    }else{
        //
        QMessageBox msgBox(
                QMessageBox::Critical,//提示框风格
                windowTitle(),//提示框标题
                "用户名或密码错误，登陆失败",//提示消息
                QMessageBox::Ok,//按钮
                this//父窗口指针
                );
        //显示提示框，并进入事件循环，当提示框按钮按下时
        //会自动退出
        msgBox.exec();
    }
}

void LoginDialog::onRejected(void){
    QMessageBox msgBox(
            QMessageBox::Question,
            windowTitle(),
            "确定要退出吗？",
            QMessageBox::No|QMessageBox::Yes,
            this
            );
    //点击Yes或No都会退出时间循环，但返回结果不一样
    //如果点击是Yes，则执行关闭窗口
    if(msgBox.exec()==QMessageBox::Yes)
        close(); //关闭登陆窗口
}
