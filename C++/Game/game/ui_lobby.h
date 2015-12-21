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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_lobby
{
public:
    QLabel *l_lobby;
    QLabel *l_host_ip;
    QLabel *l_host_port_number;
    QLabel *l_username;
    QLabel *l_users_joined;
    QTextBrowser *tb_users_joined;
    QLineEdit *le_host_ip;
    QLineEdit *le_host_port;
    QLineEdit *le_username;
    QTextBrowser *tb_clientinfo;
    QTextBrowser *tb_username;
    QTextBrowser *tb_hostinfo;
    QLabel *l_port;
    QLabel *l_your_ip;
    QLabel *l_your_ip_val;
    QLabel *l_port_number;
    QPushButton *pb_accept;
    QPushButton *pb_start;

    void setupUi(QDialog *lobby)
    {
        if (lobby->objectName().isEmpty())
            lobby->setObjectName(QStringLiteral("lobby"));
        lobby->resize(525, 415);
        l_lobby = new QLabel(lobby);
        l_lobby->setObjectName(QStringLiteral("l_lobby"));
        l_lobby->setGeometry(QRect(190, 0, 141, 61));
        l_lobby->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_host_ip = new QLabel(lobby);
        l_host_ip->setObjectName(QStringLiteral("l_host_ip"));
        l_host_ip->setGeometry(QRect(290, 140, 91, 16));
        l_host_ip->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_host_port_number = new QLabel(lobby);
        l_host_port_number->setObjectName(QStringLiteral("l_host_port_number"));
        l_host_port_number->setGeometry(QRect(290, 170, 111, 16));
        l_host_port_number->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_username = new QLabel(lobby);
        l_username->setObjectName(QStringLiteral("l_username"));
        l_username->setGeometry(QRect(250, 290, 61, 20));
        l_username->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_users_joined = new QLabel(lobby);
        l_users_joined->setObjectName(QStringLiteral("l_users_joined"));
        l_users_joined->setGeometry(QRect(10, 200, 61, 21));
        l_users_joined->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        tb_users_joined = new QTextBrowser(lobby);
        tb_users_joined->setObjectName(QStringLiteral("tb_users_joined"));
        tb_users_joined->setGeometry(QRect(5, 230, 231, 181));
        QFont font;
        font.setPointSize(12);
        tb_users_joined->setFont(font);
        tb_users_joined->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        le_host_ip = new QLineEdit(lobby);
        le_host_ip->setObjectName(QStringLiteral("le_host_ip"));
        le_host_ip->setEnabled(true);
        le_host_ip->setGeometry(QRect(410, 140, 91, 20));
        le_host_ip->setStyleSheet(QStringLiteral("selection-background-color: rgb(255, 234, 2);"));
        le_host_port = new QLineEdit(lobby);
        le_host_port->setObjectName(QStringLiteral("le_host_port"));
        le_host_port->setGeometry(QRect(410, 170, 91, 20));
        le_host_port->setStyleSheet(QStringLiteral("selection-background-color: rgb(255, 234, 2);"));
        le_username = new QLineEdit(lobby);
        le_username->setObjectName(QStringLiteral("le_username"));
        le_username->setGeometry(QRect(320, 290, 91, 20));
        le_username->setStyleSheet(QStringLiteral("selection-background-color: rgb(255, 234, 2);"));
        tb_clientinfo = new QTextBrowser(lobby);
        tb_clientinfo->setObjectName(QStringLiteral("tb_clientinfo"));
        tb_clientinfo->setGeometry(QRect(290, 70, 221, 61));
        tb_clientinfo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        tb_username = new QTextBrowser(lobby);
        tb_username->setObjectName(QStringLiteral("tb_username"));
        tb_username->setGeometry(QRect(250, 230, 161, 51));
        tb_username->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        tb_hostinfo = new QTextBrowser(lobby);
        tb_hostinfo->setObjectName(QStringLiteral("tb_hostinfo"));
        tb_hostinfo->setGeometry(QRect(10, 70, 221, 61));
        tb_hostinfo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_port = new QLabel(lobby);
        l_port->setObjectName(QStringLiteral("l_port"));
        l_port->setGeometry(QRect(10, 170, 71, 16));
        l_port->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_your_ip = new QLabel(lobby);
        l_your_ip->setObjectName(QStringLiteral("l_your_ip"));
        l_your_ip->setGeometry(QRect(10, 140, 101, 21));
        l_your_ip->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_your_ip_val = new QLabel(lobby);
        l_your_ip_val->setObjectName(QStringLiteral("l_your_ip_val"));
        l_your_ip_val->setGeometry(QRect(120, 140, 141, 20));
        l_your_ip_val->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        l_port_number = new QLabel(lobby);
        l_port_number->setObjectName(QStringLiteral("l_port_number"));
        l_port_number->setGeometry(QRect(120, 170, 141, 20));
        l_port_number->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0, 0%);"));
        pb_accept = new QPushButton(lobby);
        pb_accept->setObjectName(QStringLiteral("pb_accept"));
        pb_accept->setEnabled(false);
        pb_accept->setGeometry(QRect(250, 320, 121, 81));
        pb_start = new QPushButton(lobby);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setEnabled(false);
        pb_start->setGeometry(QRect(390, 320, 121, 81));
#ifndef QT_NO_SHORTCUT
        l_host_ip->setBuddy(le_host_ip);
        l_host_port_number->setBuddy(le_host_port);
        l_username->setBuddy(le_username);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(le_host_ip, le_host_port);
        QWidget::setTabOrder(le_host_port, le_username);
        QWidget::setTabOrder(le_username, pb_accept);
        QWidget::setTabOrder(pb_accept, tb_users_joined);
        QWidget::setTabOrder(tb_users_joined, tb_clientinfo);
        QWidget::setTabOrder(tb_clientinfo, tb_hostinfo);
        QWidget::setTabOrder(tb_hostinfo, tb_username);

        retranslateUi(lobby);

        QMetaObject::connectSlotsByName(lobby);
    } // setupUi

    void retranslateUi(QDialog *lobby)
    {
        lobby->setWindowTitle(QApplication::translate("lobby", "Lobby", 0));
        l_lobby->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:36pt;\">Lobby</span></p></body></html>", 0));
        l_host_ip->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Host IP Address:</span></p></body></html>", 0));
        l_host_port_number->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Host Port Number:</span></p></body></html>", 0));
        l_username->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Username:</span></p></body></html>", 0));
        l_users_joined->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:16pt;\">Users:</span></p></body></html>", 0));
        le_host_ip->setText(QString());
        le_host_port->setText(QApplication::translate("lobby", "25000", 0));
        tb_clientinfo->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Ask your friend that is hosting for the numbers that are showing up on their app!</span></p></body></html>", 0));
        tb_username->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Enter a username for chat (2 character min).</span></p></body></html>", 0));
        tb_hostinfo->setHtml(QApplication::translate("lobby", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">You are the host, give your friends these numbers so that they can chat with you!</span></p></body></html>", 0));
        l_port->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Port Number:</span></p></body></html>", 0));
        l_your_ip->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">Your IP Address:</span></p></body></html>", 0));
        l_your_ip_val->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">not found, click &quot;config&quot;</span></p></body></html>", 0));
        l_port_number->setText(QApplication::translate("lobby", "<html><head/><body><p><span style=\" font-size:10pt;\">click &quot;config&quot; to set port</span></p></body></html>", 0));
        pb_accept->setText(QApplication::translate("lobby", "Accept", 0));
        pb_start->setText(QApplication::translate("lobby", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class lobby: public Ui_lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
