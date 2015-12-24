/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_mainscreen
{
public:
    QPushButton *pb_send;
    QTextBrowser *tb_chat_output;
    QLineEdit *le_chat_input;

    void setupUi(QDialog *mainscreen)
    {
        if (mainscreen->objectName().isEmpty())
            mainscreen->setObjectName(QStringLiteral("mainscreen"));
        mainscreen->resize(400, 322);
        pb_send = new QPushButton(mainscreen);
        pb_send->setObjectName(QStringLiteral("pb_send"));
        pb_send->setGeometry(QRect(320, 220, 75, 91));
        tb_chat_output = new QTextBrowser(mainscreen);
        tb_chat_output->setObjectName(QStringLiteral("tb_chat_output"));
        tb_chat_output->setGeometry(QRect(10, 30, 381, 181));
        le_chat_input = new QLineEdit(mainscreen);
        le_chat_input->setObjectName(QStringLiteral("le_chat_input"));
        le_chat_input->setGeometry(QRect(10, 220, 301, 91));
        le_chat_input->setFocusPolicy(Qt::StrongFocus);
        le_chat_input->setStyleSheet(QStringLiteral(""));

        retranslateUi(mainscreen);

        QMetaObject::connectSlotsByName(mainscreen);
    } // setupUi

    void retranslateUi(QDialog *mainscreen)
    {
        mainscreen->setWindowTitle(QApplication::translate("mainscreen", "Chat Room", 0));
        pb_send->setText(QApplication::translate("mainscreen", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class mainscreen: public Ui_mainscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
