#include "StdMsgDialog.h"
#include "ui_StdMsgDialog.h"

StdMsgDialog::StdMsgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StdMsgDialog)
{
    ui->setupUi(this);
}

StdMsgDialog::~StdMsgDialog()
{
    delete ui;
    qDebug()<<"StdMsgDialog::~StdMsgDialog";
}

void StdMsgDialog::on_m_questionButton_clicked()
{
    ui->m_label->setText("Question Message Box");
    switch (QMessageBox::question(
                this,"Question消息框","你已完成...，是否结束程序?",
                QMessageBox::Ok|QMessageBox::Cancel,
                QMessageBox::Ok)) {
    case QMessageBox::Ok:
        ui->m_label->setText("Question Button/Ok");
        break;
    case QMessageBox::Cancel:
        ui->m_label->setText("Question Button/Cancel");
        break;
    default:
        break;
    }
}

void StdMsgDialog::on_m_warningButton_clicked()
{
    ui->m_label->setText("Warning Message Box");
    switch (QMessageBox::warning(
                this,"Warning消息框",
                "您修改的内容还未保存，是否要保存对文档的修改?"
                ,QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
                QMessageBox::Save)) {
    case QMessageBox::Save:
        ui->m_label->setText("Warning button/Save");
        break;
    case QMessageBox::Discard:
        ui->m_label->setText("Warning button/Discard");
        break;
    case QMessageBox::Cancel:
        ui->m_label->setText("Warning button/Cancel");
        break;
    default:
        break;
    }
}

void StdMsgDialog::on_m_aboutButton_clicked()
{
    ui->m_label->setText("About Message Box");
    QMessageBox::about(
                this,"About消息框",
                "这是一个About消息框测试！");
}

void StdMsgDialog::on_m_infoButton_clicked()
{
    ui->m_label->setText("Information Message Box");
    QMessageBox::information(
                this,"Information消息框",
                "这是一个Information消息框测试！");

}

void StdMsgDialog::on_m_criticalButton_clicked()
{
    ui->m_label->setText("Critical Message Box");
    QMessageBox::critical(
                this,"Critical消息框",
                "这是一个Critical消息框测试！");
}

void StdMsgDialog::on_m_aboutQtButton_clicked()
{
    ui->m_label->setText("About Qt Message Box");
    QMessageBox::aboutQt(
                this,"About Qt消息框");
}

void StdMsgDialog::on_pushButton_clicked()
{
    ui->m_label->setText("Custom Message Box");
    QMessageBox customMSgBox;
    customMSgBox.setWindowTitle("用户自定义消息框");
    /*QPushButton* yesBtn=*/customMSgBox.addButton("Yes",QMessageBox::ActionRole);
    /*QPushButton* noBtn=*/customMSgBox.addButton("No",QMessageBox::ActionRole);
    /*QPushButton* cancelBtn=*/customMSgBox.addButton("Cancel",QMessageBox::ActionRole);
    customMSgBox.setText("这是一个用户自定义消息框！");
    customMSgBox.setIconPixmap(QPixmap("../BaseDialog/photo.png"));
    customMSgBox.exec();
    //if(customMSgBox.clickedButton()==yesBtn)
    //    ui->m_label->setText("Custom Message Box/Yes");
    //if(customMSgBox.clickedButton()==noBtn)
    //    ui->m_label->setText("Custom Message Box/No");
    //if(customMSgBox.clickedButton()==cancelBtn)
    //    ui->m_label->setText("Custom Message Box/Cancel");
    ui->m_label->setText("Custom Message Box/"+customMSgBox.clickedButton()->text());
}

