/*************************************************************************
	> File Name: Change.cpp
	> Author:UgoLi 
	> Mail: 2653920896@qq.com
	> Created Time: 2017年09月11日 星期一 14时54分08秒
 ************************************************************************/

#include<QApplication>
#include<QDialog>
#include<QSlider>
#include<QSpinBox>


int main(int argc,char** argv){
    QApplication app(argc,argv);

    QDialog parent;
    parent.resize(200,100);

    //创建水平滑块，停靠在父窗口上
    QSlider slider(Qt::Horizontal,&parent);
    slider.move(20,20);
    slider.setRange(0,200);//设置滑动范围

    //创建选值框，停靠在父窗口上
    QSpinBox spinbox(&parent);
    spinbox.move(120,20);
    spinbox.setRange(0,200);

    QObject::connect(&slider,SIGNAL(valueChanged(int)),
                     &spinbox,SLOT(setValue(int)));
    QObject::connect(&spinbox,SIGNAL(valueChanged(int)),
                     &slider,SLOT(setValue(int)));

    //显示
    parent.show();
    return app.exec();
}



