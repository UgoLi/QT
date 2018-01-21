/********************************************************************************
** Form generated from reading UI file 'ThreadDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADDIALOG_H
#define UI_THREADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ThreadDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;

    void setupUi(QDialog *ThreadDialog)
    {
        if (ThreadDialog->objectName().isEmpty())
            ThreadDialog->setObjectName(QStringLiteral("ThreadDialog"));
        ThreadDialog->resize(328, 225);
        horizontalLayout = new QHBoxLayout(ThreadDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(ThreadDialog);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(ThreadDialog);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);

        horizontalLayout->addWidget(stopButton);


        retranslateUi(ThreadDialog);

        QMetaObject::connectSlotsByName(ThreadDialog);
    } // setupUi

    void retranslateUi(QDialog *ThreadDialog)
    {
        ThreadDialog->setWindowTitle(QApplication::translate("ThreadDialog", "ThreadDialog", Q_NULLPTR));
        startButton->setText(QApplication::translate("ThreadDialog", "\345\274\200\345\247\213\347\272\277\347\250\213", Q_NULLPTR));
        stopButton->setText(QApplication::translate("ThreadDialog", "\345\201\234\346\255\242\347\272\277\347\250\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThreadDialog: public Ui_ThreadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADDIALOG_H
