#include "gameUI.h"
#include "player.h"
#include "host.h"
#include "guest.h"

#define NUMBER_OF_SCREENS 3
#define PB_HOSTGAME_TEXT "Host"
#define PB_JOINGAME_TEXT "Join"
#define L_LOBBY_TEXT "Lobby"
#define PB_ACCEPT_TEXT "Accept settings"
#define PB_CHANGEUSERNAME_TEXT_H "Set"
#define PB_CHANGEUSERNAME_TEXT_G "Request"
#define PB_SENDCHAT_TEXT "Send"
#define L_LOBBYIPADDRESS_TEXT "IP address:"
#define L_LOBBYPORTNUMBER_TEXT "Port number:"
#define L_LOBBYCURRENTUSERS_TEXT "Users in lobby:"
#define L_LOBBYENTERUSERNAME_TEXT "Enter new username (2 character minimum):"
#define L_LOBBYCURRENTUSERNAMEDISP_TEXT "Current Username:"
#define L_LOBBYCURRENTUSERNAME_TEXT ""


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

gameUI::gameUI(QWidget *parent) : QMainWindow(parent)
{
    // initialize player type to undefined
    playerType = PLAYERTYPE::NONE;

    // initialize currently unused pointers to 0
    gamePlayer = 0;
    gameHost = 0;
    gameGuest = 0;

    // allocate a widget for each screen
    for(quint8 i = 0; i < NUMBER_OF_SCREENS; ++i)
        screenWidget[i] = new QWidget;

    // generate all screens
    setUpCosmetics();
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
    tempLayout->addWidget(centralStackedWidget,0,0);
    tempLayout->addWidget(pageComboBox,1,0);

    tempcentralWidget = new QWidget;
    tempcentralWidget->setLayout(tempLayout);
    setCentralWidget(tempcentralWidget);
}

gameUI::~gameUI()
{

}

QString gameUI::getLobbyIPAddressString()
{
    return le_lobbyIPAddress->text().simplified();
}

QString gameUI::getLobbyPortString()
{
    return le_lobbyPortNumber->text().simplified();
}

QString gameUI::getLobbyEnteredUserName()
{
    return le_lobbyEnterUserName->text().simplified();
}

void gameUI::setLobbyIPAddress(QString newIP)
{
    le_lobbyIPAddress->setText(newIP);
}

void gameUI::setLobbyPort(quint16 newPort)
{
    le_lobbyPortNumber->setText(QString::number(newPort));
}

void gameUI::setLobbyEnterUserNameText(QString enteredNameText)
{
    le_lobbyEnterUserName->setText(enteredNameText);
}

void gameUI::setLobbyCurrentUserName(QString newUserName)
{
    l_lobbyCurrentUsername->setText(newUserName);
}

void gameUI::setLobbyText(QString lobbyText)
{
    l_lobby->setText(lobbyText);
}

void gameUI::setLobbyInfoText(QString infoText)
{
    tb_lobbyInfo->setText(infoText);
}

void gameUI::setLobbyCurrentUsersText(QString currentUsersText)
{
    tb_lobbyCurrentUsers->setText(currentUsersText);
}

void gameUI::setLobbyIPAddressEnabled(bool enabled)
{
    le_lobbyIPAddress->setEnabled(enabled);
}

void gameUI::setLobbyPortEnabled(bool enabled)
{
    le_lobbyPortNumber->setEnabled(enabled);
}

void gameUI::setLobbyUserNameEnabled(bool enabled)
{
    le_lobbyEnterUserName->setEnabled(enabled);
}

void gameUI::setLobbyChangeUserNameEnabled(bool enabled)
{
    pb_changeUserName->setEnabled(enabled);
}

void gameUI::setLobbyAcceptEnabled(bool enabled)
{
    pb_accept->setEnabled(enabled);
}

void gameUI::setLobbyStartEnabled(bool enabled)
{
    pb_start->setEnabled(enabled);
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

void gameUI::setUpScreen0()
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

void gameUI::setUpScreen1()
{
    // grid layout
    screenLayout[1] = new QVBoxLayout;

    // allocate all widgets
    gl_lobbyUsers = new QGridLayout;
    gl_lobbyNetworkInfo = new QGridLayout;
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
    pb_changeUserName = new QPushButton(PB_CHANGEUSERNAME_TEXT_G);
    pb_accept = new QPushButton(PB_ACCEPT_TEXT);
    pb_start = new QPushButton("Start");

    // emit a signal whenever activity occurs on the lobby
    connect(pb_changeUserName, SIGNAL(clicked()), this, SIGNAL(userNameChangeRequested()));
    connect(pb_accept, SIGNAL(clicked()), this, SIGNAL(acceptSettingsClicked()));
    connect(pb_start, SIGNAL(clicked()), this, SIGNAL(hostStartClicked()));
    connect(le_lobbyIPAddress, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyNetworkTextChanged()));
    connect(le_lobbyPortNumber, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyNetworkTextChanged()));
    connect(le_lobbyEnterUserName, SIGNAL(textChanged(QString)), this, SIGNAL(lobbyEnterUserNameTextChanged()));
    connect(le_lobbyEnterUserName, SIGNAL(returnPressed()), pb_changeUserName, SLOT(animateClick()));

    // cosmetics
    l_lobby->setFont(font_title);
    l_lobbyCurrentUsers->setFont(font_header);
    l_lobbyCurrentUsername->setFont(font_header);
    tb_lobbyCurrentUsers->setFont(font_header);

    // network info layout
    gl_lobbyNetworkInfo->addWidget(tb_lobbyInfo,0,0,3,1);
    gl_lobbyNetworkInfo->addWidget(l_lobbyIPAddress,0,1);
    gl_lobbyNetworkInfo->addWidget(le_lobbyIPAddress,0,2);
    gl_lobbyNetworkInfo->addWidget(l_lobbyPortNumber,1,1);
    gl_lobbyNetworkInfo->addWidget(le_lobbyPortNumber,1,2);
    gl_lobbyNetworkInfo->addWidget(pb_accept,2,1,1,2);

    // username layout
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsers,0,0);
    gl_lobbyUsers->addWidget(tb_lobbyCurrentUsers,1,0,6,1);
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsernameDisp,1,1);
    gl_lobbyUsers->addWidget(l_lobbyCurrentUsername,2,1);
    gl_lobbyUsers->addWidget(l_lobbyEnterUserName,3,1);
    gl_lobbyUsers->addWidget(le_lobbyEnterUserName,4,1);
    gl_lobbyUsers->addWidget(pb_changeUserName,4,2);

    // set up screen
    vl = (QVBoxLayout*)screenLayout[1];
    vl->addWidget(l_lobby);
    vl->addLayout(gl_lobbyNetworkInfo);
    vl->addLayout(gl_lobbyUsers);
    vl->addWidget(pb_start);
    pb_start->hide();   // default is hidden
    screenWidget[1]->setLayout(vl);
}

void gameUI::setUpScreen2()
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

void gameUI::setPlayerTypeTo(PLAYERTYPE newType)
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
            pb_start->show();
            pb_changeUserName->setText(PB_CHANGEUSERNAME_TEXT_H);
            le_lobbyEnterUserName->selectAll();
            le_lobbyEnterUserName->setFocus();
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
            pb_start->hide();
            pb_changeUserName->setText(PB_CHANGEUSERNAME_TEXT_G);
            qDebug() << "allocated guest at address:" << gamePlayer << "==" << gameGuest;

        }
        break;
    default:
        qDebug() << "Warning, player type cannot be switched to PLAYERTYPE::NONE";
        break;
    }

//    qDebug() << "playerType == " << playerType;

}


void gameUI::screen0ButtonClicked(QAbstractButton *button)
{
    if(button == pb_hostGame)
    {
        setPlayerTypeTo(PLAYERTYPE::HOST);
    }
    else if(button == pb_joinGame)
    {
        setPlayerTypeTo(PLAYERTYPE::GUEST);
    }

    centralStackedWidget->setCurrentIndex(1);
}


