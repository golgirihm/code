/********************************************************************************
** Form generated from reading UI file 'form_startscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_STARTSCREEN_H
#define UI_FORM_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_startscreen
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_host;
    QPushButton *pb_join;
    QButtonGroup *bg_startscreen;

    void setupUi(QWidget *form_startscreen)
    {
        if (form_startscreen->objectName().isEmpty())
            form_startscreen->setObjectName(QStringLiteral("form_startscreen"));
        form_startscreen->resize(400, 300);
        horizontalLayout = new QHBoxLayout(form_startscreen);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pb_host = new QPushButton(form_startscreen);
        bg_startscreen = new QButtonGroup(form_startscreen);
        bg_startscreen->setObjectName(QStringLiteral("bg_startscreen"));
        bg_startscreen->addButton(pb_host);
        pb_host->setObjectName(QStringLiteral("pb_host"));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pb_host->setFont(font);

        horizontalLayout->addWidget(pb_host);

        pb_join = new QPushButton(form_startscreen);
        bg_startscreen->addButton(pb_join);
        pb_join->setObjectName(QStringLiteral("pb_join"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        pb_join->setFont(font1);

        horizontalLayout->addWidget(pb_join);


        retranslateUi(form_startscreen);

        QMetaObject::connectSlotsByName(form_startscreen);
    } // setupUi

    void retranslateUi(QWidget *form_startscreen)
    {
        form_startscreen->setWindowTitle(QApplication::translate("form_startscreen", "Form", 0));
        pb_host->setText(QApplication::translate("form_startscreen", "Host", 0));
        pb_join->setText(QApplication::translate("form_startscreen", "Join", 0));
    } // retranslateUi

};

namespace Ui {
    class form_startscreen: public Ui_form_startscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_STARTSCREEN_H
