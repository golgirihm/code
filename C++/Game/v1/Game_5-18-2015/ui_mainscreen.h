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
#include <QtWidgets/QComboBox>
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

class Ui_mainscreen
{
public:
    QGridLayout *gridLayout_2;
    QLabel *l_deck_playstack_lab_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *l_other_players_lab;
    QTextBrowser *tb_player_list;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_your_hand_lab;
    QTextBrowser *tb_your_hand;
    QGridLayout *gridLayout;
    QLabel *l_deck_playstack_lab;
    QTextBrowser *tb_playstack_card;
    QTextBrowser *tb_deck_cards;
    QVBoxLayout *PlayCardLayout;
    QComboBox *cb_choose_card;
    QPushButton *pb_play_card;
    QVBoxLayout *verticalLayout;
    QLabel *l_chatroom;
    QTextBrowser *tb_chat_output;
    QHBoxLayout *horizontalLayout_2;
    QLabel *l_username_lab;
    QLabel *l_username;
    QHBoxLayout *horizontalLayout;
    QLineEdit *le_chat_input;
    QPushButton *pb_send;

    void setupUi(QDialog *mainscreen)
    {
        if (mainscreen->objectName().isEmpty())
            mainscreen->setObjectName(QStringLiteral("mainscreen"));
        mainscreen->resize(700, 400);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainscreen->sizePolicy().hasHeightForWidth());
        mainscreen->setSizePolicy(sizePolicy);
        mainscreen->setMaximumSize(QSize(700, 400));
        gridLayout_2 = new QGridLayout(mainscreen);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        l_deck_playstack_lab_2 = new QLabel(mainscreen);
        l_deck_playstack_lab_2->setObjectName(QStringLiteral("l_deck_playstack_lab_2"));
        QFont font;
        font.setPointSize(14);
        l_deck_playstack_lab_2->setFont(font);

        gridLayout_2->addWidget(l_deck_playstack_lab_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        l_other_players_lab = new QLabel(mainscreen);
        l_other_players_lab->setObjectName(QStringLiteral("l_other_players_lab"));
        l_other_players_lab->setFont(font);

        verticalLayout_3->addWidget(l_other_players_lab);

        tb_player_list = new QTextBrowser(mainscreen);
        tb_player_list->setObjectName(QStringLiteral("tb_player_list"));
        sizePolicy.setHeightForWidth(tb_player_list->sizePolicy().hasHeightForWidth());
        tb_player_list->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(tb_player_list);


        gridLayout_2->addLayout(verticalLayout_3, 2, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        l_your_hand_lab = new QLabel(mainscreen);
        l_your_hand_lab->setObjectName(QStringLiteral("l_your_hand_lab"));
        l_your_hand_lab->setFont(font);

        verticalLayout_2->addWidget(l_your_hand_lab);

        tb_your_hand = new QTextBrowser(mainscreen);
        tb_your_hand->setObjectName(QStringLiteral("tb_your_hand"));
        sizePolicy.setHeightForWidth(tb_your_hand->sizePolicy().hasHeightForWidth());
        tb_your_hand->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(tb_your_hand);


        gridLayout_2->addLayout(verticalLayout_2, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        l_deck_playstack_lab = new QLabel(mainscreen);
        l_deck_playstack_lab->setObjectName(QStringLiteral("l_deck_playstack_lab"));
        sizePolicy.setHeightForWidth(l_deck_playstack_lab->sizePolicy().hasHeightForWidth());
        l_deck_playstack_lab->setSizePolicy(sizePolicy);
        l_deck_playstack_lab->setFont(font);

        gridLayout->addWidget(l_deck_playstack_lab, 0, 0, 2, 1);

        tb_playstack_card = new QTextBrowser(mainscreen);
        tb_playstack_card->setObjectName(QStringLiteral("tb_playstack_card"));
        sizePolicy.setHeightForWidth(tb_playstack_card->sizePolicy().hasHeightForWidth());
        tb_playstack_card->setSizePolicy(sizePolicy);
        tb_playstack_card->setMinimumSize(QSize(0, 0));
        tb_playstack_card->setMaximumSize(QSize(200, 30));

        gridLayout->addWidget(tb_playstack_card, 0, 1, 1, 1);

        tb_deck_cards = new QTextBrowser(mainscreen);
        tb_deck_cards->setObjectName(QStringLiteral("tb_deck_cards"));
        tb_deck_cards->setEnabled(true);
        sizePolicy.setHeightForWidth(tb_deck_cards->sizePolicy().hasHeightForWidth());
        tb_deck_cards->setSizePolicy(sizePolicy);
        tb_deck_cards->setMinimumSize(QSize(0, 0));
        tb_deck_cards->setMaximumSize(QSize(200, 30));

        gridLayout->addWidget(tb_deck_cards, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        PlayCardLayout = new QVBoxLayout();
        PlayCardLayout->setObjectName(QStringLiteral("PlayCardLayout"));
        cb_choose_card = new QComboBox(mainscreen);
        cb_choose_card->setObjectName(QStringLiteral("cb_choose_card"));

        PlayCardLayout->addWidget(cb_choose_card);

        pb_play_card = new QPushButton(mainscreen);
        pb_play_card->setObjectName(QStringLiteral("pb_play_card"));

        PlayCardLayout->addWidget(pb_play_card);


        gridLayout_2->addLayout(PlayCardLayout, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        l_chatroom = new QLabel(mainscreen);
        l_chatroom->setObjectName(QStringLiteral("l_chatroom"));
        l_chatroom->setFont(font);

        verticalLayout->addWidget(l_chatroom);

        tb_chat_output = new QTextBrowser(mainscreen);
        tb_chat_output->setObjectName(QStringLiteral("tb_chat_output"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_chat_output->sizePolicy().hasHeightForWidth());
        tb_chat_output->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(tb_chat_output);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        l_username_lab = new QLabel(mainscreen);
        l_username_lab->setObjectName(QStringLiteral("l_username_lab"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(l_username_lab->sizePolicy().hasHeightForWidth());
        l_username_lab->setSizePolicy(sizePolicy2);
        l_username_lab->setFont(font);
        l_username_lab->setMouseTracking(true);

        horizontalLayout_2->addWidget(l_username_lab);

        l_username = new QLabel(mainscreen);
        l_username->setObjectName(QStringLiteral("l_username"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(l_username->sizePolicy().hasHeightForWidth());
        l_username->setSizePolicy(sizePolicy3);
        l_username->setMinimumSize(QSize(0, 0));
        l_username->setFont(font);

        horizontalLayout_2->addWidget(l_username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        le_chat_input = new QLineEdit(mainscreen);
        le_chat_input->setObjectName(QStringLiteral("le_chat_input"));
        le_chat_input->setFocusPolicy(Qt::StrongFocus);
        le_chat_input->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(le_chat_input);

        pb_send = new QPushButton(mainscreen);
        pb_send->setObjectName(QStringLiteral("pb_send"));

        horizontalLayout->addWidget(pb_send);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 3, 3, 1);


        retranslateUi(mainscreen);
        QObject::connect(le_chat_input, SIGNAL(returnPressed()), pb_send, SLOT(click()));

        QMetaObject::connectSlotsByName(mainscreen);
    } // setupUi

    void retranslateUi(QDialog *mainscreen)
    {
        mainscreen->setWindowTitle(QApplication::translate("mainscreen", "Chat Room", 0));
        l_deck_playstack_lab_2->setText(QApplication::translate("mainscreen", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Your Turn!</span></p><p align=\"center\"><span style=\" font-size:16pt;\">Pick a card</span></p></body></html>", 0));
        l_other_players_lab->setText(QApplication::translate("mainscreen", "<html><head/><body><p align=\"center\">Players</p></body></html>", 0));
        l_your_hand_lab->setText(QApplication::translate("mainscreen", "<html><head/><body><p align=\"center\">Your Hand</p></body></html>", 0));
        l_deck_playstack_lab->setText(QApplication::translate("mainscreen", "<html><head/><body><p align=\"right\">Top of playstack:<br/><br/>Deck:</p></body></html>", 0));
        pb_play_card->setText(QApplication::translate("mainscreen", "Play Card", 0));
        l_chatroom->setText(QApplication::translate("mainscreen", "<html><head/><body><p align=\"center\">Chatroom</p></body></html>", 0));
        l_username_lab->setText(QApplication::translate("mainscreen", "<html><head/><body><p>Chatting as:</p></body></html>", 0));
        l_username->setText(QApplication::translate("mainscreen", "UserName", 0));
        pb_send->setText(QApplication::translate("mainscreen", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class mainscreen: public Ui_mainscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
