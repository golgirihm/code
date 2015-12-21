/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_lobby
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *l_lobby;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QTextBrowser *tb_hostinfo;
    QLabel *l_your_ip;
    QLabel *l_your_ip_val;
    QLabel *l_port;
    QLabel *l_port_number;
    QGridLayout *gridLayout_2;
    QTextBrowser *tb_clientinfo;
    QLabel *l_host_ip;
    QLabel *l_host_port_number;
    QLineEdit *le_host_port;
    QLineEdit *le_host_ip;
    QHBoxLayout *horizontalLayout_3;
    QLabel *l_users_joined;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *tb_users_joined;
    QGridLayout *gridLayout_3;
    QTextBrowser *tb_username;
    QLineEdit *le_username;
    QLabel *l_username;
    QPushButton *pb_accept;
    QPushButton *pb_start;

    void setupUi(QDialog *lobby)
    {
        if (lobby->objectName().isEmpty())
            lobby->setObjectName(QStringLiteral("lobby"));
        lobby->resize(633, 402);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lobby->sizePolicy().hasHeightForWidth());
        lobby->setSizePolicy(sizePolicy);
        lobby->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(lobby);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        l_lobby = new QLabel(lobby);
        l_lobby->setObjectName(QStringLiteral("l_lobby"));
        l_lobby->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        verticalLayout_2->addWidget(l_lobby);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(-1, 0, 0, 0);
        tb_hostinfo = new QTextBrowser(lobby);
        tb_hostinfo->setObjectName(QStringLiteral("tb_hostinfo"));
        tb_hostinfo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout->addWidget(tb_hostinfo, 0, 0, 1, 2);

        l_your_ip = new QLabel(lobby);
        l_your_ip->setObjectName(QStringLiteral("l_your_ip"));
        l_your_ip->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout->addWidget(l_your_ip, 1, 0, 1, 1);

        l_your_ip_val = new QLabel(lobby);
        l_your_ip_val->setObjectName(QStringLiteral("l_your_ip_val"));
        l_your_ip_val->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout->addWidget(l_your_ip_val, 1, 1, 1, 1);

        l_port = new QLabel(lobby);
        l_port->setObjectName(QStringLiteral("l_port"));
        l_port->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout->addWidget(l_port, 2, 0, 1, 1);

        l_port_number = new QLabel(lobby);
        l_port_number->setObjectName(QStringLiteral("l_port_number"));
        l_port_number->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout->addWidget(l_port_number, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        tb_clientinfo = new QTextBrowser(lobby);
        tb_clientinfo->setObjectName(QStringLiteral("tb_clientinfo"));
        sizePolicy.setHeightForWidth(tb_clientinfo->sizePolicy().hasHeightForWidth());
        tb_clientinfo->setSizePolicy(sizePolicy);
        tb_clientinfo->setMaximumSize(QSize(16777215, 16777215));
        tb_clientinfo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout_2->addWidget(tb_clientinfo, 0, 0, 1, 2);

        l_host_ip = new QLabel(lobby);
        l_host_ip->setObjectName(QStringLiteral("l_host_ip"));
        l_host_ip->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout_2->addWidget(l_host_ip, 1, 0, 1, 1);

        l_host_port_number = new QLabel(lobby);
        l_host_port_number->setObjectName(QStringLiteral("l_host_port_number"));
        l_host_port_number->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout_2->addWidget(l_host_port_number, 2, 0, 1, 1);

        le_host_port = new QLineEdit(lobby);
        le_host_port->setObjectName(QStringLiteral("le_host_port"));
        le_host_port->setAutoFillBackground(false);

        gridLayout_2->addWidget(le_host_port, 2, 1, 1, 1);

        le_host_ip = new QLineEdit(lobby);
        le_host_ip->setObjectName(QStringLiteral("le_host_ip"));
        le_host_ip->setEnabled(true);
        le_host_ip->setStyleSheet(QStringLiteral("selection-background-color: rgb(255, 234, 2);"));
        le_host_ip->setFrame(true);

        gridLayout_2->addWidget(le_host_ip, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        l_users_joined = new QLabel(lobby);
        l_users_joined->setObjectName(QStringLiteral("l_users_joined"));
        l_users_joined->setMinimumSize(QSize(264, 0));
        l_users_joined->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        horizontalLayout_3->addWidget(l_users_joined);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tb_users_joined = new QTextBrowser(lobby);
        tb_users_joined->setObjectName(QStringLiteral("tb_users_joined"));
        QFont font;
        font.setPointSize(10);
        tb_users_joined->setFont(font);
        tb_users_joined->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(tb_users_joined);


        horizontalLayout_2->addLayout(verticalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tb_username = new QTextBrowser(lobby);
        tb_username->setObjectName(QStringLiteral("tb_username"));
        tb_username->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout_3->addWidget(tb_username, 1, 0, 1, 3);

        le_username = new QLineEdit(lobby);
        le_username->setObjectName(QStringLiteral("le_username"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_username->sizePolicy().hasHeightForWidth());
        le_username->setSizePolicy(sizePolicy1);
        le_username->setAutoFillBackground(false);
        le_username->setClearButtonEnabled(false);

        gridLayout_3->addWidget(le_username, 2, 1, 1, 1);

        l_username = new QLabel(lobby);
        l_username->setObjectName(QStringLiteral("l_username"));
        l_username->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));

        gridLayout_3->addWidget(l_username, 2, 0, 1, 1);

        pb_accept = new QPushButton(lobby);
        pb_accept->setObjectName(QStringLiteral("pb_accept"));
        pb_accept->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_accept->sizePolicy().hasHeightForWidth());
        pb_accept->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(pb_accept, 2, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pb_start = new QPushButton(lobby);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setEnabled(false);
        pb_start->setMinimumSize(QSize(615, 30));
        pb_start->setMaximumSize(QSize(16777214, 16777215));

        verticalLayout_2->addWidget(pb_start);

        pb_start->raise();
        l_lobby->raise();
#ifndef QT_NO_SHORTCUT
        l_host_ip->setBuddy(le_host_ip);
        l_host_port_number->setBuddy(le_host_port);
        l_username->setBuddy(le_username);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(le_host_ip, le_host_port);
        QWidget::setTabOrder(le_host_port, le_username);
        QWidget::setTabOrder(le_username, tb_users_joined);
        QWidget::setTabOrder(tb_users_joined, tb_clientinfo);
        QWidget::setTabOrder(tb_clientinfo, tb_hostinfo);
        QWidget::setTabOrder(tb_hostinfo, tb_username);

        retranslateUi(lobby);
        QObject::connect(le_username, SIGNAL(returnPressed()), pb_accept, SLOT(click()));

        QMetaObject::connectSlotsByName(lobby);
    } // setupUi

    void retranslateUi(QDialog *lobby)
    {
        lobby->setWindowTitle(QApplication::translate("lobby", "Lobby", 0));
        l_lobby->setText(QApplication::translate("lobby", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Lobby</span></p></body></html>", 0));
        tb_hostinfo->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">You are the host, give your friends these numbers so that they can chat with you!</span></p></body></html>", 0));
        l_your_ip->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Your IP Address:</span></p></body></html>", 0));
        l_your_ip_val->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">not found, click &quot;config&quot;</span></p></body></html>", 0));
        l_port->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Port Number:</span></p></body></html>", 0));
        l_port_number->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">click &quot;config&quot; to set port</span></p></body></html>", 0));
        tb_clientinfo->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Ask your friend that is hosting for the numbers that are showing up on their app!</span></p></body></html>", 0));
        l_host_ip->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Host IP Address:</span></p></body></html>", 0));
        l_host_port_number->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Host Port Number:</span></p></body></html>", 0));
        le_host_port->setText(QApplication::translate("lobby", "25000", 0));
        le_host_port->setPlaceholderText(QApplication::translate("lobby", "Enter Port", 0));
        le_host_ip->setText(QApplication::translate("lobby", "192.168.0.9", 0));
        le_host_ip->setPlaceholderText(QApplication::translate("lobby", "Enter IP Address", 0));
        l_users_joined->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:16pt;\">Users:</span></p></body></html>", 0));
        tb_username->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Enter a username for chat (2 character minimum).</span></p></body></html>", 0));
        le_username->setText(QApplication::translate("lobby", "Hamid", 0));
        le_username->setPlaceholderText(QApplication::translate("lobby", "Enter Username", 0));
        l_username->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Username:</span></p></body></html>", 0));
        pb_accept->setText(QApplication::translate("lobby", "Accept", 0));
        pb_start->setText(QApplication::translate("lobby", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class lobby: public Ui_lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
