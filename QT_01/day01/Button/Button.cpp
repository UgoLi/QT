#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    //1)����GBK�������
    QTextCodec* coder = 
        QTextCodec::codecForName("GBK");

    //2)�������ַ���ת��Ϊunicode
    QPushButton button(
            coder->toUnicode("����һ����ť"));
    button.show();

    return app.exec();
}




