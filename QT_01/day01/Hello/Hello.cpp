#include <QApplication>
#include <QLabel>

int main(int argc,char* argv[])
{
    //创建应用程序对象
    QApplication app(argc,argv);

    //创建标签组件
    QLabel label("Hello World!");

    //显示标签组件
    label.show();

    //让程序进入事件循环
    return app.exec();
}



