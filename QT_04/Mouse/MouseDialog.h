#ifndef MOUSEDIALOG_H
#define MOUSEDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class MouseDialog;
}

class MouseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MouseDialog(QWidget *parent = 0);
    ~MouseDialog();

private slots:
    //鼠标按下
    /*void mousePressEvent(QMouseEvent*);
    //鼠标抬起
    void mouseReleaseEvent(QMouseEvent*);*/
    //鼠标移动
    void mouseMoveEvent(QMouseEvent*);

private:
    Ui::MouseDialog *ui;
    bool m_bDrag;//记录是否为鼠标左键选中
    QPoint m_ptPos;//记录鼠标和label相对位置
};

#endif // MOUSEDIALOG_H
