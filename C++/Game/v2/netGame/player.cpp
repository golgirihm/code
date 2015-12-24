#include "player.h"

#include <QDebug>

player::player(QWidget *parent)
    : QMainWindow(parent)
{
    info = new playerinfo;
    info->userName =  DEFAULT_USERNAME;
    info->playerNumber = -1;
}

player::~player()
{

}
