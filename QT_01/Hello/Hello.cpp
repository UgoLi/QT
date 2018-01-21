/*************************************************************************
	> File Name: Hello.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月08日 星期五 14时34分28秒
 ************************************************************************/

#include<QApplication>
#include<QLabel>
int main(int argc,char* argv[]){
    //创建应用程序对象
    QApplication app(argc,argv);

    //创建一个标签组件
    QLabel label("Hello world!");
    //显示标签组件
    label.show();
    
    //让程序进入事件循环
    return app.exec();
}
