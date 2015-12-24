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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *l_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLaypit;
    QPushButton *pb_hostgame;
    QPushButton *pb_joingame;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QButtonGroup *bg_mainmenu;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(424, 213);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(game->sizePolicy().hasHeightForWidth());
        game->setSizePolicy(sizePolicy);
        game->setAutoFillBackground(false);
        game->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0.340909, y1:0.341, x2:0.777797, y2:0.715, stop:0.221591 rgba(62, 125, 138, 125), stop:1 rgba(56, 101, 201, 127));"));
        game->setDocumentMode(false);
        centralWidget = new QWidget(game);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        l_title = new QLabel(centralWidget);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setEnabled(true);
        l_title->setMouseTracking(true);
        l_title->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        l_title->setTextFormat(Qt::AutoText);
        l_title->setScaledContents(false);

        verticalLayout_4->addWidget(l_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLaypit = new QVBoxLayout();
        verticalLaypit->setSpacing(0);
        verticalLaypit->setObjectName(QStringLiteral("verticalLaypit"));
        pb_hostgame = new QPushButton(centralWidget);
        bg_mainmenu = new QButtonGroup(game);
        bg_mainmenu->setObjectName(QStringLiteral("bg_mainmenu"));
        bg_mainmenu->addButton(pb_hostgame);
        pb_hostgame->setObjectName(QStringLiteral("pb_hostgame"));

        verticalLaypit->addWidget(pb_hostgame);

        pb_joingame = new QPushButton(centralWidget);
        bg_mainmenu->addButton(pb_joingame);
        pb_joingame->setObjectName(QStringLiteral("pb_joingame"));

        verticalLaypit->addWidget(pb_joingame);


        horizontalLayout->addLayout(verticalLaypit);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout_4->addItem(verticalSpacer);

        game->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(game);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 424, 21));
        game->setMenuBar(menuBar);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Chat!", 0));
        l_title->setText(QApplication::translate("game", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Network Chat!</span></p></body></html>", 0));
        pb_hostgame->setText(QApplication::translate("game", "Host", 0));
        pb_joingame->setText(QApplication::translate("game", "Join a friend", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
