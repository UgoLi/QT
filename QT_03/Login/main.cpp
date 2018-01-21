/*************************************************************************
	> File Name: main.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 14时51分41秒
 ************************************************************************/

#include<QApplication>
#include"LoginDialog.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    LoginDialog login;
    login.show();

    return app.exec();
}

