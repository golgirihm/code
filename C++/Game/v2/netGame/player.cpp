#include "player.h"
#include "game.h"
#include "cardstack.h"

#include <QDebug>

player::player(game *gameUI)
{
    ui = gameUI;
    info = new playerinfo;
    info->userName =  DEFAULT_USERNAME;
    info->Hand.printCards();
//    info->Hand.ToStandardDeck();

//    info->playerNumber = -1;
//    qDebug() << "My username is " << info->userName;
}

player::~player()
{
    delete info;
}
