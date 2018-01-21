#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    //1)创建GBK编码对象
    QTextCodec* coder = 
        QTextCodec::codecForName("GBK");

    //2)将中文字符串转换为unicode
    QPushButton button(
            coder->toUnicode("我是一个按钮"));
    button.show();

    return app.exec();
}




