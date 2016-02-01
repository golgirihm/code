/********************************************************************************
** Form generated from reading UI file 'form_maingame.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_MAINGAME_H
#define UI_FORM_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_maingame
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *form_maingame)
    {
        if (form_maingame->objectName().isEmpty())
            form_maingame->setObjectName(QStringLiteral("form_maingame"));
        form_maingame->resize(400, 300);
        gridLayout = new QGridLayout(form_maingame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(form_maingame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEdit = new QLineEdit(form_maingame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(form_maingame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(form_maingame);

        QMetaObject::connectSlotsByName(form_maingame);
    } // setupUi

    void retranslateUi(QWidget *form_maingame)
    {
        form_maingame->setWindowTitle(QApplication::translate("form_maingame", "Form", 0));
        label->setText(QApplication::translate("form_maingame", "This is the main game screen", 0));
        pushButton->setText(QApplication::translate("form_maingame", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class form_maingame: public Ui_form_maingame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_MAINGAME_H
