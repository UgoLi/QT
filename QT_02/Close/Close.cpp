/*************************************************************************
	> File Name: Close.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 09时18分55秒
 ************************************************************************/
//QT += widgets
#include<QApplication>
#include<QLabel>
#include<QPushButton>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    //创建一个标签和按钮
    QPushButton button("关闭标签");
    QLabel label("我是一个标签");
    //显示标签和按钮
    label.show();
    button.show();
   
    //连接信号和槽
    //点击button时发送clicked信号，label的槽函数
    //close()将自动被执行
    QObject::connect(&button,SIGNAL(pressed()),&button,SLOT(close()));
    //QObject::connect(&button,SIGNAL(clicked()),&app,SLOT(quit()));
    //QObject::connect(&button,SIGNAL(clicked()),&app,SLOT(closeAllWindows()));

    return app.exec();
}



