#ifndef SQLITEDIALOG_H
#define SQLITEDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include <QThread>

namespace Ui {
class SqliteDialog;
}

class SqliteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SqliteDialog(QWidget *parent = 0);
    ~SqliteDialog();
public:
    //创建数据库
    void createDB(void);
    //创建数据表
    void creatTable(void);
    //查询和显示
    void queryTable(void);

private slots:
    //排序槽
    void on_sortButton_clicked();
    //插入槽
    void on_insertButton_clicked();
    //删除槽
    void on_deleteButton_clicked();
    //更改槽
    void on_updateButton_clicked();

private:
    Ui::SqliteDialog *ui;
    QSqlDatabase db;//用户建立和数据库的连接
    QSqlQueryModel model;//遍历和查询结果集
};

#endif // SQLITEDIALOG_H
