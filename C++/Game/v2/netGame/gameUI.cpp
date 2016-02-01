#include "ui_form_startscreen.h"
#include "ui_form_lobby.h"
#include "ui_form_maingame.h"
#include "gameUI.h"
#include "player.h"
#include "host.h"
#include "guest.h"



#define PB0_HOSTGAME_TEXT "Host"
#define PB0_JOINGAME_TEXT "Join"
#define L1_LOBBY_TEXT "Lobby"
#define PB1_ACCEPT_TEXT "Accept settings"
#define PB1_CHANGEUSERNAME_TEXT_H "Set"
#define PB1_CHANGEUSERNAME_TEXT_G "Request"
#define L1_LOBBYIPADDRESS_TEXT "IP address:"
#define L1_LOBBYPORTNUMBER_TEXT "Port number:"
#define L1_LOBBYCURRENTUSERS_TEXT "Users in lobby:"
#define L1_LOBBYENTERUSERNAME_TEXT "Enter new username (2 character minimum):"
#define L1_LOBBYCURRENTUSERNAMEDISP_TEXT "Current Username:"
#define L1_LOBBYCURRENTUSERNAME_TEXT ""
#define PB2_SENDCHAT_TEXT "Send"


#include <QDebug>

#include <QStackedWidget>
#include <QLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QTextBrowser>
#include <QFont>
#include <QSize>

#include <QHostAddress>


gameUI::gameUI(QWidget *parent) : QMainWindow(parent)/*, ui_form1(new Ui::form_startscreen)*/

{
    /// initialize player type to undefined
    playerType = PLAYERTYPE::NONE;

    /// initialize currently unused pointers to 0
    gamePlayer = 0;
    gameHost = 0;
    gameGuest = 0;

    /// allocate a widget for each screen
    for(quint8 i = 0; i < NUMBER_OF_SCREENS; ++i)
        screenWidget[i] = new QWidget;

    /// generate all screens
    ui0 = new Ui::form_startscreen;
    ui1 = new Ui::form_lobby;
    ui2 = new Ui::form_maingame;

    setUpCosmetics();
    setUpUi0();
    setUpUi1();
    setUpUi2();

    centralStackedWidget = new QStackedWidget;
    pageComboBox = new QComboBox;

    for(quint8 i = 0; i < NUMBER_OF_SCREENS; ++i)
    {
        centralStackedWidget->addWidget(screenWidget[i]);
        pageComboBox->addItem(QString("Page ") + QString::number(i));
    }

    connect(pageComboBox, SIGNAL(activated(int)), centralStackedWidget, SLOT(setCurrentIndex(int)));

    tempLayout = new QVBoxLayout;
    tempLayout->addWidget(centralStackedWidget);
    tempLayout->addWidget(pageComboBox);


    tempcentralWidget = new QWidget;
    tempcentralWidget->setLayout(tempLayout);
    setCentralWidget(tempcentralWidget);


}

gameUI::~gameUI()
{

}

QHostAddress gameUI::get_le1_IPAddress()
{
    return  QHostAddress(ui1->le_IPAddress->text().simplified());
}

int gameUI::get_le1_portNumber()
{
    return ui1->le_portNumber->text().simplified().toInt();
}

QString gameUI::get_le1_enterUserName()
{
    return ui1->le_enterUserName->text().simplified();
}

/// \todo REMOVE
QPushButton *gameUI::get_pb1_accept()
{
    return ui1->pb_accept;
}

/// \todo REMOVE
QPushButton *gameUI::get_pb1_changeUserName()
{
    return ui1->pb_changeUserName;
}

void gameUI::set_le1_IPAddress(QHostAddress newIP)
{
    ui1->le_IPAddress->setText(newIP.toString());
}

void gameUI::set_le1_portNumber(quint16 newPort)
{
    ui1->le_portNumber->setText(QString::number(newPort));
}

void gameUI::set_le1_enterUserName(QString enteredNameText)
{
    ui1->le_enterUserName->setText(enteredNameText);
}

void gameUI::set_l1_currentUsername(QString newUserName)
{
    ui1->l_currentUserName->setText(newUserName);
}

void gameUI::set_l1_lobby(QString lobbyText)
{
    ui1->l_lobby->setText(lobbyText);
}

void gameUI::set_tb1_info(QString infoText)
{
    ui1->tb_info->setText(infoText);
}

void gameUI::set_tb1_currentUsers(QString currentUsersText)
{
    ui1->tb_currentUsers->setText(currentUsersText);
}

void gameUI::setEnabled_le1_IPAddress(bool enabled)
{
    ui1->le_IPAddress->setEnabled(enabled);
}

void gameUI::setEnabled_le1_portNumber(bool enabled)
{
    ui1->le_portNumber->setEnabled(enabled);
}

void gameUI::setEnabled_le1_enterUserName(bool enabled)
{
    ui1->le_enterUserName->setEnabled(enabled);
}

void gameUI::setEnabled_pb1_changeUserName(bool enabled)
{
    ui1->pb_changeUserName->setEnabled(enabled);
}

void gameUI::setEnabled_pb1_accept(bool enabled)
{
    ui1->pb_accept->setEnabled(enabled);
}

void gameUI::setEnabled_pb1_start(bool enabled)
{
    ui1->pb_start->setEnabled(enabled);
}

void gameUI::setUpCosmetics()
{
    font_title.setPointSize(32);
    font_title.setBold(true);
    font_header.setPointSize(18);
    font_distinct.setBold(true);
    size_tbInitial.setHeight(400);
    size_tbInitial.setWidth(400);
}

void gameUI::setUpUi0()
{
    ui0->setupUi(screenWidget[0]);

    /// handle clicks
    connect(ui0->bg_startscreen,  SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(ui0buttonclicked(QAbstractButton*)));

    /// cosmetics
    ui0->pb_host->setFont(font_distinct);
    ui0->pb_join->setFont(font_distinct);
}

void gameUI::setUpUi1()
{
    ui1->setupUi(screenWidget[1]);

    /// emit a signal whenever activity occurs on the lobby
    connect(ui1->pb_changeUserName, SIGNAL(clicked()), this, SIGNAL(userNameChangeRequested()));
    connect(ui1->pb_accept, SIGNAL(clicked()), this, SIGNAL(acceptSettingsClicked()));
    connect(ui1->pb_start, SIGNAL(clicked()), this, SIGNAL(hostStartClicked()));
    connect(ui1->le_IPAddress, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyNetworkTextChanged()));
    connect(ui1->le_portNumber, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyNetworkTextChanged()));
    connect(ui1->le_enterUserName, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyEnterUserNameTextChanged()));
    connect(ui1->le_enterUserName, SIGNAL(returnPressed()), ui1->pb_changeUserName, SLOT(animateClick()));

    /// cosmetics
    ui1->l_lobby->setFont(font_title);
    ui1->l_currentUsers->setFont(font_header);
    ui1->l_currentUserName->setFont(font_header);
    ui1->tb_currentUsers->setFont(font_header);

    ui1->pb_start->hide();   /// default is hidden
}

void gameUI::setUpUi2()
{
    ui2->setupUi(screenWidget[2]);
}

void gameUI::setPlayerTypeTo(PLAYERTYPE newType)
{
    switch(newType)
    {
    case PLAYERTYPE::HOST:
        playerType = newType;
        if(gameHost == 0)
        {
            if(gameGuest)
            {
                qDebug() << "deleting guest at address:" << gamePlayer << gameGuest;
                delete gameGuest;
                gameGuest = 0;
            }

            gameHost = new host(this);
            gamePlayer = gameHost;
            ui1->pb_start->show();
            ui1->pb_changeUserName->setText(PB1_CHANGEUSERNAME_TEXT_H);
            ui1->le_enterUserName->selectAll();
            ui1->le_enterUserName->setFocus();
            qDebug() << "allocated host at address:" << gamePlayer << "==" << gameHost;


        }
        break;
    case PLAYERTYPE::GUEST:
        playerType = newType;
        if(gameGuest == 0)
        {
            if(gameHost)
            {
                qDebug() << "deleting host at address:" << gamePlayer <<  gameHost;
                delete gameHost;
                gameHost = 0;
            }

            gameGuest = new guest(this);
            gamePlayer = gameGuest;
            ui1->pb_start->hide();
            ui1->pb_changeUserName->setText(PB1_CHANGEUSERNAME_TEXT_G);
            qDebug() << "allocated guest at address:" << gamePlayer << "==" << gameGuest;

        }
        break;
    default:
        qDebug() << "Warning, player type cannot be switched to PLAYERTYPE::NONE";
        break;
    }

//    qDebug() << "playerType == " << playerType;

}


void gameUI::ui0buttonclicked(QAbstractButton *button)
{
    if(button == ui0->pb_host)
    {
        setPlayerTypeTo(PLAYERTYPE::HOST);
    }
    else if(button == ui0->pb_join)
    {
        setPlayerTypeTo(PLAYERTYPE::GUEST);
    }

    centralStackedWidget->setCurrentIndex(1);
}


