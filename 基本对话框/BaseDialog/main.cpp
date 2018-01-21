#include "BaseDialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置启动画面
    QSplashScreen splash(QPixmap("../BaseDialog/startImage/Qt.png"));//Qt.png,startScreen.jpg
    splash.show();
    a.processEvents();

    BaseDialog w;
    w.show();

    splash.finish(&w);//主窗体初始化完成，关闭启动画面

    return a.exec();
}
