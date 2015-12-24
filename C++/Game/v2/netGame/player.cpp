#include "player.h"

#include <QDebug>

player::player()
{
    info = new playerinfo;
    info->userName =  DEFAULT_USERNAME;
//    info->Hand.ToStandardDeck();

//    info->playerNumber = -1;
//    qDebug() << "My username is " << info->userName;
}

player::~player()
{
    delete info;
}
