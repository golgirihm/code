#include "game.h"
#include "player.h"
#include "host.h"
#include "guest.h"

#define NUMBER_OF_SCREENS 3
#define PB_HOSTGAME_TEXT "Host"
#define PB_JOINGAME_TEXT "Join"
#define L_LOBBY_TEXT "Lobby"
#define PB_ACCEPT_TEXT "Accept all settings"
#define PB_CHANGEUSERNAME_TEXT "Request"
#define PB_SENDCHAT_TEXT "Send"
#define L_LOBBYIPADDRESS_TEXT "IP address:"
#define L_LOBBYPORTNUMBER_TEXT "Port number:"
#define L_LOBBYCURRENTUSERS_TEXT "Users in lobby:"
#define L_LOBBYENTERUSERNAME_TEXT "Enter new username:"
#define L_LOBBYCURRENTUSERNAMEDISP_TEXT "Current Username:"
#define L_LOBBYCURRENTUSERNAME_TEXT "DefaultPlayerName"


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

game::game(QWidget *parent) : QMainWindow(parent)
{
    // initialize player type to undefined
    playerType = PLAYERTYPE::NONE;

    // allocate a widget for each screen
    for(quint8 i = 0; i < NUMBER_OF_SCREENS; ++i)
    {
        screenWidget[i] = new QWidget;
    }


    // initialize currently unused pointers to 0
    gamePlayer = 0;
    gameHost = 0;
    gameGuest = 0;

    // set up cosmetics
    font_title.setPointSize(32);
    font_title.setBold(true);
    font_header.setPointSize(18);
    font_distinct.setBold(true);
    size_tbInitial.setHeight(400);
    size_tbInitial.setWidth(400);


    // place all widgets
    setUpScreen0();
    setUpScreen1();
    setUpScreen2();

    centralStackedWidget = new QStackedWidget;
    pageComboBox = new QComboBox;

    for(quint8 i = 0; i < NUMBER_OF_SCREENS; ++i)
    {
        centralStackedWidget->addWidget(screenWidget[i]);
        pageComboBox->addItem(QString("Page ") + QString::number(i));
    }

    connect(pageComboBox, SIGNAL(activated(int)), centralStackedWidget, SLOT(setCurrentIndex(int)));

    tempLayout = new QGridLayout;
    tempLayout->addWidget(centralStackedWidget);
    tempLayout->addWidget(pageComboBox,1,0);

    tempcentralWidget = new QWidget;
    tempcentralWidget->setLayout(tempLayout);
    setCentralWidget(tempcentralWidget);

    centralStackedWidget->setCurrentIndex(1);
}

game::~game()
{

}

QString game::getLobbyIPAddress()
{
    return le_lobbyIPAddress->text();
}

quint16 game::getLobbyPort()
{
    return (quint16)le_lobbyPortNumber->text().toInt();
}

QString game::getLobbyEnteredUserName()
{
    return le_lobbyEnterUserName->text();
}

void game::setLobbyIPAddress(QString newIP)
{
    le_lobbyIPAddress->setText(newIP);
}

void game::setLobbyPort(quint16 newPort)
{
    le_lobbyPortNumber->setText(QString::number(newPort));
}

void game::setLobbyUserName(QString newUserName)
{
    l_lobbyCurrentUsername->setText(newUserName);
}

void game::setLobbyInfoText(QString InfoText)
{
    tb_lobbyInfo->setText(InfoText);
}

void game::setLobbyCurrentUsersText(QString CurrentUsersText)
{
    tb_lobbyCurrentUsers->setText(CurrentUsersText);
}

void game::setUpScreen0()
{
    // horizontal layout
    screenLayout[0] = new QHBoxLayout;

    pb_hostGame = new QPushButton(PB_HOSTGAME_TEXT);
    pb_joinGame = new QPushButton(PB_JOINGAME_TEXT);
    bg_mainmenu = new QButtonGroup;

    // let bg_mainmenu capture button clicks
    bg_mainmenu->addButton(pb_hostGame);
    bg_mainmenu->addButton(pb_joinGame);
    connect(bg_mainmenu, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(screen0ButtonClicked(QAbstractButton*)));

    // cosmetics
    pb_hostGame->setFont(font_distinct);
    pb_joinGame->setFont(font_distinct);

    // set up screen
    hl = (QHBoxLayout*)screenLayout[0];
    hl->addWidget(pb_hostGame);
    hl->addWidget(pb_joinGame);
    screenWidget[0]->setLayout(hl);
}

void game::setUpScreen1()
{
    // grid layout
    screenLayout[1] = new QVBoxLayout;

    // allocate all widgets
    gl_lobbyUsers = new QGridLayout;
    gl_lobbyNetworkInfo = new QGridLayout;
    gl_lobbyMainButtons = new QGridLayout;
    l_lobby = new QLabel(L_LOBBY_TEXT);
    l_lobbyIPAddress = new QLabel(L_LOBBYIPADDRESS_TEXT);
    l_lobbyPortNumber = new QLabel(L_LOBBYPORTNUMBER_TEXT);
    l_lobbyCurrentUsers = new QLabel(L_LOBBYCURRENTUSERS_TEXT);
    l_lobbyCurrentUsernameDisp = new QLabel(L_LOBBYCURRENTUSERNAMEDISP_TEXT);
    l_lobbyCurrentUsername = new QLabel(L_LOBBYCURRENTUSERNAME_TEXT);
    l_lobbyEnterUserName = new QLabel(L_LOBBYENTERUSERNAME_TEXT);
    tb_lobbyInfo = new QTextBrowser();
    tb_lobbyCurrentUsers = new QTextBrowser();
    le_lobbyIPAddress = new QLineEdit;
    le_lobbyPortNumber = new QLineEdit;
    le_lobbyEnterUserName = new QLineEdit;
    pb_changeUserName = new QPushButton(PB_CHANGEUSERNAME_TEXT);
    pb_accept = new QPushButton(PB_ACCEPT_TEXT);
    pb_start = new QPushButton("Start");

    // emit a signal whenever the change username button is clicked
    connect(pb_changeUserName, SIGNAL(clicked()), this, SIGNAL(userNameChangeRequested()));

    // cosmetics
    l_lobby->setFont(font_title);
    l_lobbyCurrentUsers->setFont(font_header);
    l_lobbyCurrentUsername->setFont(font_header);
    tb_lobbyCurrentUsers->setFont(font_header);

    // network info layout
    gl_lobbyNetworkInfo->addWidget(tb_lobbyInfo,0,0,2,1);
    gl_lobbyNetworkInfo->addWidget(l_lobbyIPAddress,0,1);
    gl_lobbyNetworkInfo->addWidget(le_lobbyIPAddress,0,2);
    gl_lobbyNetworkInfo->addWidget(l_lobbyPortNumber,1,1);
    gl_lobbyNetworkInfo->addWidget(le_lobbyPortNumber,1,2);

    // username layout
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsers,0,0);
    gl_lobbyUsers->addWidget(tb_lobbyCurrentUsers,1,0,6,1);
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsernameDisp,1,1);
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsername,2,1);
    gl_lobbyUsers->addWidget(l_lobbyEnterUserName,3,1);
    gl_lobbyUsers->addWidget(le_lobbyEnterUserName,4,1);
    gl_lobbyUsers->addWidget(pb_changeUserName,4,2);

    // main buttons layout
    gl_lobbyMainButtons->addWidget(pb_accept,0,0);
    gl_lobbyMainButtons->addWidget(pb_start,0,1);

    // set up screen
    vl = (QVBoxLayout*)screenLayout[1];
    vl->addWidget(l_lobby);
    vl->addLayout(gl_lobbyNetworkInfo);
    vl->addLayout(gl_lobbyUsers);
    vl->addLayout(gl_lobbyMainButtons);
    screenWidget[1]->setLayout(vl);
}

void game::setUpScreen2()
{
    // grid layout
    screenLayout[2] = new QGridLayout;

    le_chatInput = new QLineEdit;
    pb_sendChat = new QPushButton(PB_SENDCHAT_TEXT);

    // set up screen
    gl = (QGridLayout*)screenLayout[2];
    gl->addWidget(le_chatInput);
    gl->addWidget(pb_sendChat);
    screenWidget[2]->setLayout(gl);
}

void game::setPlayerTypeTo(game::PLAYERTYPE newType)
{
    switch(newType)
    {
    case PLAYERTYPE::HOST:
        playerType = newType;
        if(!gameHost)
        {
            if(gameGuest)
            {
                qDebug() << "deleting guest at address:" << gamePlayer << gameGuest;
                delete gameGuest;
                gameGuest = 0;
            }

            gameHost = new host(this);
            gamePlayer = gameHost;
            qDebug() << "allocated host at address:" << gamePlayer << "==" << gameHost;



        }
        break;
    case PLAYERTYPE::GUEST:
        playerType = newType;
        if(!gameGuest)
        {
            if(gameHost)
            {
                qDebug() << "deleting host at address:" << gamePlayer <<  gameHost;
                delete gameHost;
                gameHost = 0;
            }

            gameGuest = new guest(this);
            gamePlayer = gameGuest;
            qDebug() << "allocated guest at address:" << gamePlayer << "==" << gameGuest;
        }
        break;
    default:
        qDebug() << "Warning, player type cannot be switched to PLAYERTYPE::NONE";
        break;
    }

//    qDebug() << "playerType == " << playerType;

}

void game::screen0ButtonClicked(QAbstractButton *button)
{
    if(button == pb_hostGame)
    {
        setPlayerTypeTo(PLAYERTYPE::HOST);
        gameHost->sendTest();
    }
    else if(button == pb_joinGame)
    {
        setPlayerTypeTo(PLAYERTYPE::GUEST);
        gameGuest->sendTest();
    }

}


