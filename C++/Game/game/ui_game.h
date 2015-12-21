/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralWidget;
    QPushButton *pb_joingame;
    QPushButton *pb_hostgame;
    QLabel *l_title;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *bg_mainmenu;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(525, 415);
        game->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));"));
        game->setDocumentMode(false);
        centralWidget = new QWidget(game);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pb_joingame = new QPushButton(centralWidget);
        bg_mainmenu = new QButtonGroup(game);
        bg_mainmenu->setObjectName(QStringLiteral("bg_mainmenu"));
        bg_mainmenu->addButton(pb_joingame);
        pb_joingame->setObjectName(QStringLiteral("pb_joingame"));
        pb_joingame->setGeometry(QRect(80, 170, 361, 23));
        pb_hostgame = new QPushButton(centralWidget);
        bg_mainmenu->addButton(pb_hostgame);
        pb_hostgame->setObjectName(QStringLiteral("pb_hostgame"));
        pb_hostgame->setGeometry(QRect(80, 140, 361, 23));
        l_title = new QLabel(centralWidget);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setEnabled(true);
        l_title->setGeometry(QRect(180, 30, 151, 71));
        l_title->setMouseTracking(true);
        l_title->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        l_title->setTextFormat(Qt::AutoText);
        l_title->setScaledContents(false);
        game->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(game);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 525, 21));
        game->setMenuBar(menuBar);
        mainToolBar = new QToolBar(game);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        game->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(game);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        game->setStatusBar(statusBar);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Chat!", 0));
        pb_joingame->setText(QApplication::translate("game", "Join a friend", 0));
        pb_hostgame->setText(QApplication::translate("game", "Host", 0));
        l_title->setText(QApplication::translate("game", "<html><head/><body><p><span style=\" font-size:48pt;\">Chat!</span></p></body></html>", 0));
        mainToolBar->setWindowTitle(QApplication::translate("game", "Chat!", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
