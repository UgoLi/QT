/*************************************************************************
	> File Name: Parent.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 11时43分30秒
 ************************************************************************/

#include<QApplication>
#include<QPushButton>
#include<QLabel>
#include<QWidget>
#include<QDialog>
#include<QMainWindow>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    
    //创建父窗口
    //QWidget parent;
    //QMainWindow parent;
    QDialog parent;
    
    //调整位置和大小
    parent.move(360,225);
    parent.resize(720,450);
   
    //创建标签组件停靠在父窗口上
    QLabel* label = 
        new QLabel("我是一个标签",&parent);
    label->move(100,150);


    QPushButton* button = 
        new QPushButton("退出",&parent);
    button->move(100,200);
    button->resize(80,80);

    //显示父窗口
    parent.show();
   
    QObject::connect(button,SIGNAL(clicked()),&parent,SLOT(close()));
    


    return app.exec();
}//自动释放父窗口时，子空间也自动释放
