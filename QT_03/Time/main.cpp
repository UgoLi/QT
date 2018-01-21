/*************************************************************************
	> File Name: main.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月12日 星期二 09时51分53秒
 ************************************************************************/

#include<QApplication>
#include"TimeDialog.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);

    TimeDialog time;
    time.show();

    return app.exec();
}

