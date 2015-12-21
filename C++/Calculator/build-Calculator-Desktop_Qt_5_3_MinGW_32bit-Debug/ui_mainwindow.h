/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *b_equals;
    QLineEdit *e_input;
    QTextBrowser *t_output;
    QLabel *l_Rectangular;
    QLabel *l_Polar;
    QRadioButton *radio_degrees;
    QRadioButton *radio_radians;
    QRadioButton *radio_grads;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *l_x;
    QLabel *l_y;
    QLabel *l_z;
    QLineEdit *e_x;
    QLineEdit *e_y;
    QLineEdit *e_z;
    QPushButton *b_plus;
    QPushButton *b_minus;
    QPushButton *b_divide;
    QPushButton *b_multiply;
    QPushButton *b_8;
    QPushButton *b_2;
    QPushButton *b_point;
    QPushButton *b_5;
    QPushButton *b_1;
    QPushButton *b_0;
    QPushButton *b_4;
    QPushButton *b_6;
    QPushButton *b_3;
    QPushButton *b_9;
    QPushButton *b_7;
    QPushButton *b_sin;
    QPushButton *b_cos;
    QPushButton *b_tan;
    QPushButton *b_mod;
    QLabel *l_asterisk;
    QPushButton *b_angle;
    QPushButton *b_conj;
    QPushButton *b_arg;
    QPushButton *b_mag;
    QPushButton *b_clear;
    QPushButton *b_parenth_r;
    QPushButton *b_parenth_l;
    QPushButton *b_j;
    QButtonGroup *CalcRadioButtons;
    QButtonGroup *CalcPushButtons;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(407, 284);
        MainWindow->setStyleSheet(QStringLiteral("alternate-background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        b_equals = new QPushButton(centralWidget);
        CalcPushButtons = new QButtonGroup(MainWindow);
        CalcPushButtons->setObjectName(QStringLiteral("CalcPushButtons"));
        CalcPushButtons->addButton(b_equals);
        b_equals->setObjectName(QStringLiteral("b_equals"));
        b_equals->setGeometry(QRect(370, 210, 30, 71));
        e_input = new QLineEdit(centralWidget);
        e_input->setObjectName(QStringLiteral("e_input"));
        e_input->setGeometry(QRect(10, 10, 391, 20));
        e_input->setStyleSheet(QStringLiteral(""));
        t_output = new QTextBrowser(centralWidget);
        t_output->setObjectName(QStringLiteral("t_output"));
        t_output->setGeometry(QRect(80, 35, 241, 51));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        t_output->setFont(font);
        l_Rectangular = new QLabel(centralWidget);
        l_Rectangular->setObjectName(QStringLiteral("l_Rectangular"));
        l_Rectangular->setGeometry(QRect(10, 40, 61, 16));
        l_Polar = new QLabel(centralWidget);
        l_Polar->setObjectName(QStringLiteral("l_Polar"));
        l_Polar->setGeometry(QRect(10, 70, 71, 16));
        radio_degrees = new QRadioButton(centralWidget);
        CalcRadioButtons = new QButtonGroup(MainWindow);
        CalcRadioButtons->setObjectName(QStringLiteral("CalcRadioButtons"));
        CalcRadioButtons->addButton(radio_degrees);
        radio_degrees->setObjectName(QStringLiteral("radio_degrees"));
        radio_degrees->setGeometry(QRect(340, 40, 61, 17));
        radio_degrees->setChecked(true);
        radio_radians = new QRadioButton(centralWidget);
        CalcRadioButtons->addButton(radio_radians);
        radio_radians->setObjectName(QStringLiteral("radio_radians"));
        radio_radians->setGeometry(QRect(340, 60, 61, 17));
        radio_grads = new QRadioButton(centralWidget);
        CalcRadioButtons->addButton(radio_grads);
        radio_grads->setObjectName(QStringLiteral("radio_grads"));
        radio_grads->setGeometry(QRect(340, 80, 61, 17));
        radio_grads->setChecked(false);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 100, 31, 53));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        l_x = new QLabel(layoutWidget);
        l_x->setObjectName(QStringLiteral("l_x"));

        verticalLayout->addWidget(l_x);

        l_y = new QLabel(layoutWidget);
        l_y->setObjectName(QStringLiteral("l_y"));

        verticalLayout->addWidget(l_y);

        l_z = new QLabel(layoutWidget);
        l_z->setObjectName(QStringLiteral("l_z"));

        verticalLayout->addWidget(l_z);

        e_x = new QLineEdit(centralWidget);
        e_x->setObjectName(QStringLiteral("e_x"));
        e_x->setGeometry(QRect(30, 100, 131, 16));
        e_x->setStyleSheet(QStringLiteral(""));
        e_y = new QLineEdit(centralWidget);
        e_y->setObjectName(QStringLiteral("e_y"));
        e_y->setGeometry(QRect(30, 120, 131, 16));
        e_y->setStyleSheet(QStringLiteral(""));
        e_z = new QLineEdit(centralWidget);
        e_z->setObjectName(QStringLiteral("e_z"));
        e_z->setGeometry(QRect(30, 140, 131, 16));
        e_z->setStyleSheet(QStringLiteral(""));
        b_plus = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_plus);
        b_plus->setObjectName(QStringLiteral("b_plus"));
        b_plus->setGeometry(QRect(330, 250, 30, 30));
        b_minus = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_minus);
        b_minus->setObjectName(QStringLiteral("b_minus"));
        b_minus->setGeometry(QRect(330, 210, 30, 30));
        b_divide = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_divide);
        b_divide->setObjectName(QStringLiteral("b_divide"));
        b_divide->setGeometry(QRect(330, 130, 30, 30));
        b_multiply = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_multiply);
        b_multiply->setObjectName(QStringLiteral("b_multiply"));
        b_multiply->setGeometry(QRect(330, 170, 30, 30));
        b_8 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_8);
        b_8->setObjectName(QStringLiteral("b_8"));
        b_8->setGeometry(QRect(250, 130, 30, 30));
        b_2 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_2);
        b_2->setObjectName(QStringLiteral("b_2"));
        b_2->setGeometry(QRect(250, 210, 30, 30));
        b_point = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_point);
        b_point->setObjectName(QStringLiteral("b_point"));
        b_point->setGeometry(QRect(290, 250, 30, 30));
        b_5 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_5);
        b_5->setObjectName(QStringLiteral("b_5"));
        b_5->setGeometry(QRect(250, 170, 30, 30));
        b_1 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_1);
        b_1->setObjectName(QStringLiteral("b_1"));
        b_1->setGeometry(QRect(210, 210, 30, 30));
        b_0 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_0);
        b_0->setObjectName(QStringLiteral("b_0"));
        b_0->setGeometry(QRect(210, 250, 71, 30));
        b_4 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_4);
        b_4->setObjectName(QStringLiteral("b_4"));
        b_4->setGeometry(QRect(210, 170, 30, 30));
        b_6 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_6);
        b_6->setObjectName(QStringLiteral("b_6"));
        b_6->setGeometry(QRect(290, 170, 30, 30));
        b_3 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_3);
        b_3->setObjectName(QStringLiteral("b_3"));
        b_3->setGeometry(QRect(290, 210, 30, 30));
        b_9 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_9);
        b_9->setObjectName(QStringLiteral("b_9"));
        b_9->setGeometry(QRect(290, 130, 30, 30));
        b_7 = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_7);
        b_7->setObjectName(QStringLiteral("b_7"));
        b_7->setGeometry(QRect(210, 130, 30, 30));
        b_sin = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_sin);
        b_sin->setObjectName(QStringLiteral("b_sin"));
        b_sin->setGeometry(QRect(170, 130, 30, 30));
        b_cos = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_cos);
        b_cos->setObjectName(QStringLiteral("b_cos"));
        b_cos->setGeometry(QRect(170, 170, 30, 30));
        b_tan = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_tan);
        b_tan->setObjectName(QStringLiteral("b_tan"));
        b_tan->setGeometry(QRect(170, 210, 30, 30));
        b_mod = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_mod);
        b_mod->setObjectName(QStringLiteral("b_mod"));
        b_mod->setGeometry(QRect(170, 250, 30, 30));
        l_asterisk = new QLabel(centralWidget);
        l_asterisk->setObjectName(QStringLiteral("l_asterisk"));
        l_asterisk->setEnabled(true);
        l_asterisk->setGeometry(QRect(70, 30, 16, 16));
        b_angle = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_angle);
        b_angle->setObjectName(QStringLiteral("b_angle"));
        b_angle->setGeometry(QRect(370, 170, 30, 30));
        b_conj = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_conj);
        b_conj->setObjectName(QStringLiteral("b_conj"));
        b_conj->setGeometry(QRect(130, 250, 30, 30));
        b_arg = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_arg);
        b_arg->setObjectName(QStringLiteral("b_arg"));
        b_arg->setGeometry(QRect(130, 170, 30, 30));
        b_mag = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_mag);
        b_mag->setObjectName(QStringLiteral("b_mag"));
        b_mag->setGeometry(QRect(130, 210, 30, 30));
        b_clear = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_clear);
        b_clear->setObjectName(QStringLiteral("b_clear"));
        b_clear->setGeometry(QRect(250, 90, 30, 30));
        b_parenth_r = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_parenth_r);
        b_parenth_r->setObjectName(QStringLiteral("b_parenth_r"));
        b_parenth_r->setGeometry(QRect(210, 90, 30, 30));
        b_parenth_l = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_parenth_l);
        b_parenth_l->setObjectName(QStringLiteral("b_parenth_l"));
        b_parenth_l->setGeometry(QRect(170, 90, 30, 30));
        b_j = new QPushButton(centralWidget);
        CalcPushButtons->addButton(b_j);
        b_j->setObjectName(QStringLiteral("b_j"));
        b_j->setGeometry(QRect(370, 130, 30, 30));
        MainWindow->setCentralWidget(centralWidget);
        l_asterisk->raise();
        b_equals->raise();
        t_output->raise();
        l_Rectangular->raise();
        l_Polar->raise();
        radio_degrees->raise();
        radio_radians->raise();
        radio_grads->raise();
        layoutWidget->raise();
        b_plus->raise();
        b_minus->raise();
        b_divide->raise();
        b_multiply->raise();
        b_8->raise();
        b_2->raise();
        b_point->raise();
        b_5->raise();
        b_1->raise();
        b_0->raise();
        b_4->raise();
        b_6->raise();
        b_3->raise();
        b_9->raise();
        b_7->raise();
        b_sin->raise();
        b_cos->raise();
        b_tan->raise();
        b_mod->raise();
        e_input->raise();
        e_x->raise();
        e_y->raise();
        e_z->raise();
        b_angle->raise();
        b_conj->raise();
        b_arg->raise();
        b_mag->raise();
        b_clear->raise();
        b_parenth_r->raise();
        b_parenth_l->raise();
        b_j->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        b_equals->setText(QApplication::translate("MainWindow", "=", 0));
        l_Rectangular->setText(QApplication::translate("MainWindow", "Rectangular:", 0));
        l_Polar->setText(QApplication::translate("MainWindow", "Polar:      a =", 0));
        radio_degrees->setText(QApplication::translate("MainWindow", "Degrees", 0));
        radio_radians->setText(QApplication::translate("MainWindow", "Radians", 0));
        radio_grads->setText(QApplication::translate("MainWindow", "Grads", 0));
        l_x->setText(QApplication::translate("MainWindow", "x =", 0));
        l_y->setText(QApplication::translate("MainWindow", "y =", 0));
        l_z->setText(QApplication::translate("MainWindow", "z =", 0));
        b_plus->setText(QApplication::translate("MainWindow", "+", 0));
        b_minus->setText(QApplication::translate("MainWindow", "-", 0));
        b_divide->setText(QApplication::translate("MainWindow", "/", 0));
        b_multiply->setText(QApplication::translate("MainWindow", "*", 0));
        b_8->setText(QApplication::translate("MainWindow", "8", 0));
        b_2->setText(QApplication::translate("MainWindow", "2", 0));
        b_point->setText(QApplication::translate("MainWindow", ".", 0));
        b_5->setText(QApplication::translate("MainWindow", "5", 0));
        b_1->setText(QApplication::translate("MainWindow", "1", 0));
        b_0->setText(QApplication::translate("MainWindow", "0", 0));
        b_4->setText(QApplication::translate("MainWindow", "4", 0));
        b_6->setText(QApplication::translate("MainWindow", "6", 0));
        b_3->setText(QApplication::translate("MainWindow", "3", 0));
        b_9->setText(QApplication::translate("MainWindow", "9", 0));
        b_7->setText(QApplication::translate("MainWindow", "7", 0));
        b_sin->setText(QApplication::translate("MainWindow", "sin", 0));
        b_cos->setText(QApplication::translate("MainWindow", "cos", 0));
        b_tan->setText(QApplication::translate("MainWindow", "tan", 0));
        b_mod->setText(QApplication::translate("MainWindow", "mod", 0));
        l_asterisk->setText(QApplication::translate("MainWindow", "*", 0));
        b_angle->setText(QApplication::translate("MainWindow", "/_", 0));
        b_conj->setText(QApplication::translate("MainWindow", "conj", 0));
        b_arg->setText(QApplication::translate("MainWindow", "arg", 0));
        b_mag->setText(QApplication::translate("MainWindow", "mag", 0));
        b_clear->setText(QApplication::translate("MainWindow", "C", 0));
        b_parenth_r->setText(QApplication::translate("MainWindow", ")", 0));
        b_parenth_l->setText(QApplication::translate("MainWindow", "(", 0));
        b_j->setText(QApplication::translate("MainWindow", "j", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
