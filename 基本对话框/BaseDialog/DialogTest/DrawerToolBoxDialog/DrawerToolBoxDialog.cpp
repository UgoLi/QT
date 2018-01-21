#include "DrawerToolBoxDialog.h"
#include "ui_DrawerToolBoxDialog.h"

DrawerToolBoxDialog::DrawerToolBoxDialog(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::DrawerToolBoxDialog)
{
    ui->setupUi(this);
    ui->toolButton_1->setIcon(QIcon(QPixmap("11.png")));
    ui->toolButton_2->setIcon(QIcon(QPixmap("12.png")));
    ui->toolButton_3->setIcon(QIcon(QPixmap("13.png")));
    ui->toolButton_4->setIcon(QIcon(QPixmap("14.png")));
    ui->toolButton_5->setIcon(QIcon(QPixmap("15.png")));

    ui->toolButton_21->setIcon(QIcon(QPixmap("21.png")));
    ui->toolButton_22->setIcon(QIcon(QPixmap("22.png")));

    ui->toolButton_31->setIcon(QIcon(QPixmap("31.png")));
    ui->toolButton_32->setIcon(QIcon(QPixmap("32.png")));
}

DrawerToolBoxDialog::~DrawerToolBoxDialog()
{
    delete ui;
    qDebug()<<"DrawerToolBox::~DrawerToolBox";
}
