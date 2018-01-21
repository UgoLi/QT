/********************************************************************************
** Form generated from reading UI file 'ErnieDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERNIEDIALOG_H
#define UI_ERNIEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ErnieDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *m_name;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ErnieDialog)
    {
        if (ErnieDialog->objectName().isEmpty())
            ErnieDialog->setObjectName(QStringLiteral("ErnieDialog"));
        ErnieDialog->resize(329, 342);
        ErnieDialog->setSizeGripEnabled(true);
        ErnieDialog->setModal(true);
        verticalLayout = new QVBoxLayout(ErnieDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(ErnieDialog);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(24, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ErnieDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        m_name = new QLineEdit(ErnieDialog);
        m_name->setObjectName(QStringLiteral("m_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_name->sizePolicy().hasHeightForWidth());
        m_name->setSizePolicy(sizePolicy1);
        m_name->setAlignment(Qt::AlignCenter);
        m_name->setReadOnly(true);

        horizontalLayout->addWidget(m_name);

        horizontalSpacer_2 = new QSpacerItem(52, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ErnieDialog);

        QMetaObject::connectSlotsByName(ErnieDialog);
    } // setupUi

    void retranslateUi(QDialog *ErnieDialog)
    {
        ErnieDialog->setWindowTitle(QApplication::translate("ErnieDialog", "\346\221\207\345\245\226\345\231\250", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ErnieDialog", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErnieDialog: public Ui_ErnieDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERNIEDIALOG_H
