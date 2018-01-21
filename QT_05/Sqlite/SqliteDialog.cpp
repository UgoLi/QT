#include "SqliteDialog.h"
#include "ui_SqliteDialog.h"

SqliteDialog::SqliteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SqliteDialog)
{
    ui->setupUi(this);
    createDB();
    creatTable();
    queryTable();
}

SqliteDialog::~SqliteDialog()
{
    delete ui;
}
//创建数据库
void SqliteDialog:: createDB(void)
{
    //添加数据库驱动“QSQLITE”
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库的名字
    db.setDatabaseName("menu.db");
    //打开数据库
    if(db.open()==false){
        qDebug()<<"打开数据库失败";
        QMessageBox::critical(
                    this,"Error","打开数据库失败");
    }
}

//创建数据表
void SqliteDialog:: creatTable(void)
{
    //构建sql语句
    QString str=QString(
                "CREATE TABLE student\
                 (id INT PRIMARY KEY NOT NULL,\
                 name TEXT NOT NULL,score REAL NOT NULL)");
    qDebug()<<str;
    //创建一个执行sql语句对象
    QSqlQuery query;
    query.exec(str);
}

//查询和显示
void SqliteDialog:: queryTable(void)
{
    //查询
    QString str=QString("SELECT * FROM student");
    model.setQuery(str);
    ui->tableView->setModel(&model);
}


void SqliteDialog::on_sortButton_clicked()
{
    QString value=ui->valueComboBox->currentText();
    QString cond=ui->condComboBox->currentText();

    qDebug()<<value<<","<<cond;

    QString str;

    if(value=="ID"){
        if(cond=="升序"){
            str=QString("SELECT * FROM student ORDER BY id ASC");

        }
        if(cond=="降序"){
           str=QString("SELECT * FROM student ORDER BY id DESC");

        }
    }

    if(value=="Score"){
        if(cond=="升序"){
            str=QString("SELECT * FROM student ORDER BY score ASC");

        }
        if(cond=="降序"){
            str=QString("SELECT * FROM student ORDER BY score DESC");

        }
    }
    model.setQuery(str);
    ui->tableView->setModel(&model);

    //sleep(10);

}

void SqliteDialog::on_insertButton_clicked()
{
    int id=ui->idEdit->text().toInt();
    QString name=ui->nameEdit->text();
    double score=ui->scoreEdit->text().toDouble();

    QString str=QString(
        "INSERT INTO student VALUES(%1,'%2',%3)"
        ).arg(id).arg(name).arg(score);
    qDebug()<<str;
    QSqlQuery query;
    query.exec(str);

    queryTable();
}

void SqliteDialog::on_deleteButton_clicked()
{
    int id=ui->idEdit->text().toInt();
    //QString name=ui->nameEdit->text();
    //double score=ui->scoreEdit->text().toDouble();

    QString str=QString(
        "DELETE FROM student WHERE id=%1"
        ).arg(id);
    qDebug()<<str;
    QSqlQuery query;
    query.exec(str);

    queryTable();
}

void SqliteDialog::on_updateButton_clicked()
{
    int id=ui->idEdit->text().toInt();
    QString name=ui->nameEdit->text();
    double score=ui->scoreEdit->text().toDouble();

    QString str=QString(
        "UPDATE student SET name='%1',score=%2 WHERE id=%3"
        ).arg(name).arg(score).arg(id);
    qDebug()<<str;
    QSqlQuery query;
    query.exec(str);

    queryTable();
}
