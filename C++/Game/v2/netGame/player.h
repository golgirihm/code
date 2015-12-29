#ifndef PLAYER_H
#define PLAYER_H

#define DEFAULT_USERNAME "DefaultPlayerName"

class game;
#include "cardstack.h"

#include <QDebug>

struct playerinfo
{
    QString userName;
//    qint8 playerNumber;
    cardstack Hand;
};

class player : public QObject
{
    Q_OBJECT

public:
    player(game *gameUI);
    ~player();

public slots:

protected:
    game *ui;
    playerinfo *info;





};

#endif // PLAYER_H
