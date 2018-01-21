/*************************************************************************
	> File Name: main.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 16时16分29秒
 ************************************************************************/

#include<QApplication>
#include"CalculatorDialog.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);

    CalculatorDialog calc;
    calc.show();

    return app.exec();
}



