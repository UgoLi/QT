#include "KryBoardDialog.h"
#include "ui_KryBoardDialog.h"

KryBoardDialog::KryBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KryBoardDialog)
{
    ui->setupUi(this);
}

KryBoardDialog::~KryBoardDialog()
{
    delete ui;
}
void KryBoardDialog::keyPressEvent(QKeyEvent* event)
{
    printKeyEvent("按键按下",event);
}

void KryBoardDialog::keyReleaseEvent(QKeyEvent* event)
{
    printKeyEvent("按键抬起",event);
}

void KryBoardDialog::printKeyEvent(const QString& action,QKeyEvent* event)
{
    qDebug()<<action;
    qDebug("按键代码:%d",event->key());
    qDebug()<<"按键文本："<<event->text();
}
