/********************************************************************************
** Form generated from reading UI file 'form_lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LOBBY_H
#define UI_FORM_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_lobby
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *l_lobby;
    QHBoxLayout *hl_info;
    QTextBrowser *tb_info;
    QFormLayout *fl_networkinfo;
    QLabel *l_IPAdress;
    QLineEdit *le_IPAddress;
    QLabel *l_portNumber;
    QLineEdit *le_portNumber;
    QPushButton *pb_accept;
    QGridLayout *gl_users;
    QLabel *l_currentUsers;
    QLabel *l_currentUserName;
    QLabel *l_userNameHint;
    QLabel *l_enterUserName;
    QHBoxLayout *hl_enterUserName;
    QLineEdit *le_enterUserName;
    QPushButton *pb_changeUserName;
    QTextBrowser *tb_currentUsers;
    QPushButton *pb_start;

    void setupUi(QWidget *form_lobby)
    {
        if (form_lobby->objectName().isEmpty())
            form_lobby->setObjectName(QStringLiteral("form_lobby"));
        form_lobby->setEnabled(true);
        form_lobby->resize(438, 295);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(form_lobby->sizePolicy().hasHeightForWidth());
        form_lobby->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(form_lobby);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        l_lobby = new QLabel(form_lobby);
        l_lobby->setObjectName(QStringLiteral("l_lobby"));
        l_lobby->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(l_lobby);

        hl_info = new QHBoxLayout();
        hl_info->setObjectName(QStringLiteral("hl_info"));
        tb_info = new QTextBrowser(form_lobby);
        tb_info->setObjectName(QStringLiteral("tb_info"));
        tb_info->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_info->sizePolicy().hasHeightForWidth());
        tb_info->setSizePolicy(sizePolicy1);
        tb_info->setMaximumSize(QSize(200, 100));

        hl_info->addWidget(tb_info);

        fl_networkinfo = new QFormLayout();
        fl_networkinfo->setObjectName(QStringLiteral("fl_networkinfo"));
        fl_networkinfo->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        fl_networkinfo->setRowWrapPolicy(QFormLayout::WrapLongRows);
        fl_networkinfo->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fl_networkinfo->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        l_IPAdress = new QLabel(form_lobby);
        l_IPAdress->setObjectName(QStringLiteral("l_IPAdress"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(l_IPAdress->sizePolicy().hasHeightForWidth());
        l_IPAdress->setSizePolicy(sizePolicy2);
        l_IPAdress->setMinimumSize(QSize(50, 20));

        fl_networkinfo->setWidget(0, QFormLayout::LabelRole, l_IPAdress);

        le_IPAddress = new QLineEdit(form_lobby);
        le_IPAddress->setObjectName(QStringLiteral("le_IPAddress"));
        sizePolicy2.setHeightForWidth(le_IPAddress->sizePolicy().hasHeightForWidth());
        le_IPAddress->setSizePolicy(sizePolicy2);
        le_IPAddress->setMinimumSize(QSize(50, 20));

        fl_networkinfo->setWidget(0, QFormLayout::FieldRole, le_IPAddress);

        l_portNumber = new QLabel(form_lobby);
        l_portNumber->setObjectName(QStringLiteral("l_portNumber"));
        sizePolicy2.setHeightForWidth(l_portNumber->sizePolicy().hasHeightForWidth());
        l_portNumber->setSizePolicy(sizePolicy2);
        l_portNumber->setMinimumSize(QSize(50, 20));

        fl_networkinfo->setWidget(1, QFormLayout::LabelRole, l_portNumber);

        le_portNumber = new QLineEdit(form_lobby);
        le_portNumber->setObjectName(QStringLiteral("le_portNumber"));
        sizePolicy2.setHeightForWidth(le_portNumber->sizePolicy().hasHeightForWidth());
        le_portNumber->setSizePolicy(sizePolicy2);
        le_portNumber->setMinimumSize(QSize(50, 20));

        fl_networkinfo->setWidget(1, QFormLayout::FieldRole, le_portNumber);

        pb_accept = new QPushButton(form_lobby);
        pb_accept->setObjectName(QStringLiteral("pb_accept"));
        sizePolicy2.setHeightForWidth(pb_accept->sizePolicy().hasHeightForWidth());
        pb_accept->setSizePolicy(sizePolicy2);
        pb_accept->setMinimumSize(QSize(50, 20));

        fl_networkinfo->setWidget(2, QFormLayout::SpanningRole, pb_accept);


        hl_info->addLayout(fl_networkinfo);


        verticalLayout->addLayout(hl_info);

        gl_users = new QGridLayout();
        gl_users->setObjectName(QStringLiteral("gl_users"));
        l_currentUsers = new QLabel(form_lobby);
        l_currentUsers->setObjectName(QStringLiteral("l_currentUsers"));

        gl_users->addWidget(l_currentUsers, 0, 0, 1, 1);

        l_currentUserName = new QLabel(form_lobby);
        l_currentUserName->setObjectName(QStringLiteral("l_currentUserName"));

        gl_users->addWidget(l_currentUserName, 3, 1, 1, 1);

        l_userNameHint = new QLabel(form_lobby);
        l_userNameHint->setObjectName(QStringLiteral("l_userNameHint"));

        gl_users->addWidget(l_userNameHint, 4, 1, 1, 1);

        l_enterUserName = new QLabel(form_lobby);
        l_enterUserName->setObjectName(QStringLiteral("l_enterUserName"));

        gl_users->addWidget(l_enterUserName, 2, 1, 1, 1);

        hl_enterUserName = new QHBoxLayout();
        hl_enterUserName->setObjectName(QStringLiteral("hl_enterUserName"));
        le_enterUserName = new QLineEdit(form_lobby);
        le_enterUserName->setObjectName(QStringLiteral("le_enterUserName"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(le_enterUserName->sizePolicy().hasHeightForWidth());
        le_enterUserName->setSizePolicy(sizePolicy3);

        hl_enterUserName->addWidget(le_enterUserName);

        pb_changeUserName = new QPushButton(form_lobby);
        pb_changeUserName->setObjectName(QStringLiteral("pb_changeUserName"));
        sizePolicy3.setHeightForWidth(pb_changeUserName->sizePolicy().hasHeightForWidth());
        pb_changeUserName->setSizePolicy(sizePolicy3);

        hl_enterUserName->addWidget(pb_changeUserName);


        gl_users->addLayout(hl_enterUserName, 5, 1, 1, 1);

        tb_currentUsers = new QTextBrowser(form_lobby);
        tb_currentUsers->setObjectName(QStringLiteral("tb_currentUsers"));
        sizePolicy.setHeightForWidth(tb_currentUsers->sizePolicy().hasHeightForWidth());
        tb_currentUsers->setSizePolicy(sizePolicy);
        tb_currentUsers->setMinimumSize(QSize(200, 100));
        tb_currentUsers->setMaximumSize(QSize(200, 16777215));

        gl_users->addWidget(tb_currentUsers, 2, 0, 4, 1);


        verticalLayout->addLayout(gl_users);

        pb_start = new QPushButton(form_lobby);
        pb_start->setObjectName(QStringLiteral("pb_start"));

        verticalLayout->addWidget(pb_start);


        retranslateUi(form_lobby);

        QMetaObject::connectSlotsByName(form_lobby);
    } // setupUi

    void retranslateUi(QWidget *form_lobby)
    {
        form_lobby->setWindowTitle(QApplication::translate("form_lobby", "Form", 0));
        l_lobby->setText(QApplication::translate("form_lobby", "Lobby", 0));
        l_IPAdress->setText(QApplication::translate("form_lobby", "IP address", 0));
        l_portNumber->setText(QApplication::translate("form_lobby", "Port number", 0));
        pb_accept->setText(QApplication::translate("form_lobby", "Accept settings", 0));
        l_currentUsers->setText(QApplication::translate("form_lobby", "Users in lobby:", 0));
        l_currentUserName->setText(QString());
        l_userNameHint->setText(QApplication::translate("form_lobby", "Enter new username (2 character minimum):", 0));
        l_enterUserName->setText(QApplication::translate("form_lobby", "Current Username:", 0));
        pb_changeUserName->setText(QApplication::translate("form_lobby", "Set", 0));
        pb_start->setText(QApplication::translate("form_lobby", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class form_lobby: public Ui_form_lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LOBBY_H
