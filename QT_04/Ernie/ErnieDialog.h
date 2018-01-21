#ifndef ERNIEDIALOG_H
#define ERNIEDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QDir>
#include <QTime>//设置随机种子
#include <QVector>//容器，保存所有图片
#include <QDebug>

namespace Ui {
class ErnieDialog;
}

class ErnieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErnieDialog(QWidget *parent = 0);
    ~ErnieDialog();

private slots:
    void on_pushButton_clicked();

private:
    //绘图事件函数
    void paintEvent(QPaintEvent*);
    //定时器事件函数
    void timerEvent(QTimerEvent*);
    //加载path路径下的所有图片
    void loadPhotos(const QString& path);

private:
    Ui::ErnieDialog *ui;
    //定义容器对象，每个元素类型都是QImage
    //用户保存从目录中读取到所有图片
    QVector <QImage> m_vecPhotos;
    QVector <QString> m_vecName;
    int m_index;//图片索引
    int m_idtPhoto;//换图的定时器
    bool isStarted;//标记状态：true正在摇奖
};

#endif // ERNIEDIALOG_H
