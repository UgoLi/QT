#ifndef DRAWERTOOLBOX_H
#define DRAWERTOOLBOX_H

#include <QToolBox>
#include <QDebug>

namespace Ui {
class DrawerToolBoxDialog;
}

class DrawerToolBoxDialog: public QToolBox
{
    Q_OBJECT

public:
    explicit DrawerToolBoxDialog(QWidget *parent = 0);
    ~DrawerToolBoxDialog();

private:
    Ui::DrawerToolBoxDialog *ui;
};

#endif // DRAWERTOOLBOX_H
