#ifndef GUEST_H
#define GUEST_H

#include "player.h"
class netclient;

class guest : public player
{
public:
    guest(game *gameUI);
    ~guest();

    netclient *netClient;

public slots:
    void sendTest();
};

#endif // GUEST_H
