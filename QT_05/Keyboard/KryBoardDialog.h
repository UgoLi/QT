#ifndef KRYBOARDDIALOG_H
#define KRYBOARDDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QKeyEvent>

namespace Ui {
class KryBoardDialog;
}

class KryBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KryBoardDialog(QWidget *parent = 0);
    ~KryBoardDialog();
private:
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void printKeyEvent(const QString&,QKeyEvent*);

private:
    Ui::KryBoardDialog *ui;
};

#endif // KRYBOARDDIALOG_H
