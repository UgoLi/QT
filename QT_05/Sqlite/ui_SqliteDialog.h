/********************************************************************************
** Form generated from reading UI file 'SqliteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLITEDIALOG_H
#define UI_SQLITEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SqliteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *valueComboBox;
    QComboBox *condComboBox;
    QPushButton *sortButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *idEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *scoreEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    void setupUi(QDialog *SqliteDialog)
    {
        if (SqliteDialog->objectName().isEmpty())
            SqliteDialog->setObjectName(QStringLiteral("SqliteDialog"));
        SqliteDialog->resize(479, 498);
        verticalLayout = new QVBoxLayout(SqliteDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        valueComboBox = new QComboBox(SqliteDialog);
        valueComboBox->setObjectName(QStringLiteral("valueComboBox"));

        horizontalLayout->addWidget(valueComboBox);

        condComboBox = new QComboBox(SqliteDialog);
        condComboBox->setObjectName(QStringLiteral("condComboBox"));

        horizontalLayout->addWidget(condComboBox);

        sortButton = new QPushButton(SqliteDialog);
        sortButton->setObjectName(QStringLiteral("sortButton"));

        horizontalLayout->addWidget(sortButton);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(SqliteDialog);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(SqliteDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        idEdit = new QLineEdit(SqliteDialog);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        horizontalLayout_3->addWidget(idEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(SqliteDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        nameEdit = new QLineEdit(SqliteDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        horizontalLayout_4->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(SqliteDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        scoreEdit = new QLineEdit(SqliteDialog);
        scoreEdit->setObjectName(QStringLiteral("scoreEdit"));

        horizontalLayout_5->addWidget(scoreEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        insertButton = new QPushButton(SqliteDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout_2->addWidget(insertButton);

        deleteButton = new QPushButton(SqliteDialog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);

        updateButton = new QPushButton(SqliteDialog);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout_2->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SqliteDialog);

        QMetaObject::connectSlotsByName(SqliteDialog);
    } // setupUi

    void retranslateUi(QDialog *SqliteDialog)
    {
        SqliteDialog->setWindowTitle(QApplication::translate("SqliteDialog", "SqliteDialog", Q_NULLPTR));
        valueComboBox->clear();
        valueComboBox->insertItems(0, QStringList()
         << QApplication::translate("SqliteDialog", "ID", Q_NULLPTR)
         << QApplication::translate("SqliteDialog", "Score", Q_NULLPTR)
        );
        condComboBox->clear();
        condComboBox->insertItems(0, QStringList()
         << QApplication::translate("SqliteDialog", "\345\215\207\345\272\217", Q_NULLPTR)
         << QApplication::translate("SqliteDialog", "\351\231\215\345\272\217", Q_NULLPTR)
        );
        sortButton->setText(QApplication::translate("SqliteDialog", "\346\216\222\345\272\217", Q_NULLPTR));
        label->setText(QApplication::translate("SqliteDialog", "\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        idEdit->setText(QApplication::translate("SqliteDialog", "10011", Q_NULLPTR));
        label_2->setText(QApplication::translate("SqliteDialog", "\345\255\246\347\224\237\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        nameEdit->setText(QApplication::translate("SqliteDialog", "Tom", Q_NULLPTR));
        label_3->setText(QApplication::translate("SqliteDialog", "\345\255\246\347\224\237\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        scoreEdit->setText(QApplication::translate("SqliteDialog", "85.5", Q_NULLPTR));
        insertButton->setText(QApplication::translate("SqliteDialog", "\346\217\222\345\205\245", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("SqliteDialog", "\345\210\240\351\231\244", Q_NULLPTR));
        updateButton->setText(QApplication::translate("SqliteDialog", "\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SqliteDialog: public Ui_SqliteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLITEDIALOG_H
