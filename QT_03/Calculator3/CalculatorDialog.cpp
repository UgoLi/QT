#include "CalculatorDialog.h"
#include "ui_CalculatorDialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);

    ui->m_editx->setValidator(new QDoubleValidator());
    ui->m_edity->setValidator(new QDoubleValidator());

    connect(ui->m_editx,SIGNAL(textChanged(QString)),this,SLOT(enabledCalcButton()));
    connect(ui->m_edity,SIGNAL(textChanged(QString)),this,SLOT(enabledCalcButton()));
    connect(ui->m_btnCalc,SIGNAL(clicked()),this,SLOT(calcClicked()));
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

void CalculatorDialog::enabledCalcButton(){
    bool xOk,yOk;
    ui->m_editx->text().toDouble(&xOk);
    ui->m_edity->text().toDouble(&yOk);
    ui->m_btnCalc->setEnabled(xOk && yOk);
}

void CalculatorDialog::calcClicked(){
    double res=ui->m_editx->text().toDouble()+
            ui->m_edity->text().toDouble();
    ui->m_editZ->setText(QString::number(res));
}
