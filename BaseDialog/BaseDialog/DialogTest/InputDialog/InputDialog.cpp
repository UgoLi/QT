#include "InputDialog.h"
#include "ui_InputDialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
    qDebug()<<"InputDialog::~InputDialog";
}

//弹出标准文本输入对话框
void InputDialog::on_m_changeNameButton_clicked()
{
    bool ok;
    QString name=QInputDialog::getText(
                this,"标准字符串输入对话框","请输入姓名：",QLineEdit::Normal,ui->m_nameEdit->text(),&ok);
    if(ok){
        ui->m_nameEdit->setText(name);
    }
}

//弹出标准选择对话框
void InputDialog::on_m_changeSexButton_clicked()
{
    QStringList sexItem;
    sexItem<<"男"<<"女";
    bool ok;
    QString sex=QInputDialog::getItem(
                this,"标准条目选择对话框","请选择性别:",sexItem,0,false,&ok);
    if(ok){
        ui->m_sexEdit->setText(sex);
    }
}

//弹出标准整数输入
void InputDialog::on_m_changeAgeButton_clicked()
{
    bool ok;
    int age=QInputDialog::getInt(
                this,"标准int类型输入对话框","请输入年龄:",ui->m_ageEdit->text().toInt(),0,120,1,&ok);
    if(ok){
        ui->m_ageEdit->setText(QString("%1").arg(age));
    }
}

//弹出标准浮点数输入
void InputDialog::on_m_changeScoreButton_clicked()
{
    bool ok;
    double score=QInputDialog::getDouble(
                this,"标准double类型输入对话框","请输入成绩:",ui->m_scoreEdit->text().toDouble(),0,100,1,&ok);
    if(ok){
        ui->m_scoreEdit->setText(QString("%1").arg(score));
    }
}
