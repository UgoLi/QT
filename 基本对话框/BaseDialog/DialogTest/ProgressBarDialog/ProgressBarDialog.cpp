#include "ProgressBarDialog.h"
#include "ui_ProgressBarDialog.h"

ProgressBarDialog::ProgressBarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBarDialog)
{
    ui->setupUi(this);
    ui->m_fileNumEdit->setValidator(new QIntValidator);
}

ProgressBarDialog::~ProgressBarDialog()
{
    delete ui;
    qDebug()<<"ProgressBarDialog::~ProgressBarDialog";
}

void ProgressBarDialog::on_m_startButton_clicked()
{
    ui->m_startButton->setEnabled(false);
    bool ok;
    int num=ui->m_fileNumEdit->text().toInt(&ok);
    ok=bool(num) & ok;
    if(!ok)ui->lbl_fileNum->setText("100");
    if(ok){
        if(ui->m_showTypeBox->currentIndex()==0){//选择进度条显示方式

            ui->m_progressBar->setRange(1,num);
            for(int i=1;i<num+1;i++){
                QThread::msleep(100);
                ui->m_progressBar->setValue(i);
            }

        }
        else if(ui->m_showTypeBox->currentIndex()==1){//选择进度对话框显示
            ui->m_startButton->setEnabled(false);
            QProgressDialog* progressDialog=new QProgressDialog();
            QFont font("ZYsong18030",12);
            progressDialog->setFont(font);
            progressDialog->setWindowModality(Qt::WindowModal);
            progressDialog->setMinimumDuration(5);
            progressDialog->setWindowTitle("Please Wait");
            progressDialog->setLabelText("Copying...");
            progressDialog->setCancelButtonText("Cancel");
            progressDialog->setRange(1,num);
            for(int i=1;i<num+1;i++){
                QThread::msleep(100);
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled()){
                    ui->m_startButton->setEnabled(true);
                    return;
                }
            }
            //progressDialog->exec();
        }
        ui->m_startButton->setEnabled(true);
    }
}
