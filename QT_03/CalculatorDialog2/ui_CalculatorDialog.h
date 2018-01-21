/********************************************************************************
** Form generated from reading UI file 'CalculatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editx;
    QLabel *m_labadd;
    QLineEdit *m_edity;
    QPushButton *m_btnCalc;
    QLineEdit *m_editZ;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName(QStringLiteral("CalculatorDialog"));
        CalculatorDialog->resize(573, 206);
        QFont font;
        font.setPointSize(18);
        CalculatorDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(CalculatorDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_editx = new QLineEdit(CalculatorDialog);
        m_editx->setObjectName(QStringLiteral("m_editx"));
        m_editx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editx);

        m_labadd = new QLabel(CalculatorDialog);
        m_labadd->setObjectName(QStringLiteral("m_labadd"));

        horizontalLayout->addWidget(m_labadd);

        m_edity = new QLineEdit(CalculatorDialog);
        m_edity->setObjectName(QStringLiteral("m_edity"));
        m_edity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_edity);

        m_btnCalc = new QPushButton(CalculatorDialog);
        m_btnCalc->setObjectName(QStringLiteral("m_btnCalc"));
        m_btnCalc->setEnabled(false);

        horizontalLayout->addWidget(m_btnCalc);

        m_editZ = new QLineEdit(CalculatorDialog);
        m_editZ->setObjectName(QStringLiteral("m_editZ"));
        m_editZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_editZ->setReadOnly(true);

        horizontalLayout->addWidget(m_editZ);


        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QApplication::translate("CalculatorDialog", "\345\212\240\346\263\225\350\256\241\347\256\227\345\231\250", Q_NULLPTR));
        m_labadd->setText(QApplication::translate("CalculatorDialog", "+", Q_NULLPTR));
        m_btnCalc->setText(QApplication::translate("CalculatorDialog", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
