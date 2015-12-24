#include "game.h"

#define HOST_GAME_TEXT "Host"
#define JOIN_GAME_TEXT "Join"


#include <QDebug>

game::game(QWidget *parent) : QMainWindow(parent)
{
    playerType = PLAYERTYPE::NONE;

    // allocate memory
    centralWidget = new QWidget;
    layout = new QGridLayout;
    bg_mainmenu = new QButtonGroup;

    // initialize other pointers to 0
    gamePlayer = 0;
    gameHost = 0;
    gameGuest = 0;

    // pb_hostGame
    pb_hostGame = new QPushButton;
    pb_hostGame->setText(HOST_GAME_TEXT);
    bg_mainmenu->addButton(pb_hostGame);
    layout->addWidget(pb_hostGame,0,0);

    // pb_joinGame
    pb_joinGame = new QPushButton;
    pb_joinGame->setText(JOIN_GAME_TEXT);
    bg_mainmenu->addButton(pb_joinGame);
    layout->addWidget(pb_joinGame,0,1);

    // let bg_mainmenu capture button clicks
    connect(bg_mainmenu, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(mainMenuButtonClicked(QAbstractButton*)));

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}

game::~game()
{

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
                qDebug() << "deleting guest at address:" << gameGuest;
                delete gameGuest;
                gameGuest = 0;
            }

            gameHost = new host;
            gamePlayer = gameHost;
            qDebug() << "allocating host at address:" << gamePlayer << "==" << gameHost;

        }
        break;
    case PLAYERTYPE::GUEST:
        playerType = newType;
        if(!gameGuest)
        {
            if(gameHost)
            {
                qDebug() << "deleting host at address:" << gameHost;
                delete gameHost;
                gameHost = 0;
            }

            gameGuest = new guest;
            gamePlayer = gameGuest;
            qDebug() << "allocating guest at address:" << gamePlayer << "==" << gameGuest;
        }
        break;
    default:
        qDebug() << "Warning, player type cannot be switched to PLAYERTYPE::NONE";
        break;
    }

//    qDebug() << "playerType == " << playerType;

}

void game::mainMenuButtonClicked(QAbstractButton *button)
{
    if(button == pb_hostGame)
    {
        setPlayerTypeTo(PLAYERTYPE::HOST);
    }
    else if(button == pb_joinGame)
    {
        setPlayerTypeTo(PLAYERTYPE::GUEST);
    }

}

