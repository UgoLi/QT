/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *m_labeluser;
    QLineEdit *m_username;
    QLabel *m_labelpwd;
    QLineEdit *m_password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *m_btnBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(414, 143);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_labeluser = new QLabel(LoginDialog);
        m_labeluser->setObjectName(QStringLiteral("m_labeluser"));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        m_labeluser->setFont(font);

        gridLayout->addWidget(m_labeluser, 0, 0, 1, 1);

        m_username = new QLineEdit(LoginDialog);
        m_username->setObjectName(QStringLiteral("m_username"));

        gridLayout->addWidget(m_username, 0, 1, 1, 1);

        m_labelpwd = new QLabel(LoginDialog);
        m_labelpwd->setObjectName(QStringLiteral("m_labelpwd"));
        m_labelpwd->setFont(font);

        gridLayout->addWidget(m_labelpwd, 1, 0, 1, 1);

        m_password = new QLineEdit(LoginDialog);
        m_password->setObjectName(QStringLiteral("m_password"));
        m_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        m_password->setFrame(true);
        m_password->setEchoMode(QLineEdit::Password);
        m_password->setCursorPosition(0);
        m_password->setDragEnabled(false);

        gridLayout->addWidget(m_password, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_btnBox = new QDialogButtonBox(LoginDialog);
        m_btnBox->setObjectName(QStringLiteral("m_btnBox"));
        m_btnBox->setLayoutDirection(Qt::RightToLeft);
        m_btnBox->setAutoFillBackground(false);
        m_btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(m_btnBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", Q_NULLPTR));
        m_labeluser->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        m_labelpwd->setText(QApplication::translate("LoginDialog", "\345\257\206    \347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
