#ifndef SHOWPICSDIALOG_H
#define SHOWPICSDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class ShowPicsDialog;
}

class ShowPicsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPicsDialog(QWidget *parent = 0);
    ~ShowPicsDialog();

private slots:
    //自动生成的槽函数，会自动连接到对应按钮的信号
    void on_m_btnPrev_clicked();

    void on_m_btnNext_clicked();

    void on_m_next_clicked();

    void on_m_prev_clicked();

    //自定义鼠标移动事件
    void mouseMoveEvent(QMouseEvent* );

private:
    //绘制事件虚函数
    void paintEvent(QPaintEvent *event);
    int m_idxImage;//图片索引

    Ui::ShowPicsDialog *ui;

    QRect* rcPrev;
    QRect* rcNext;
};

#endif // SHOWPICSDIALOG_H
