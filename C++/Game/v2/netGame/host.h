#ifndef HOST_H
#define HOST_H

#include "player.h"
class netserver;

class host : public player
{
public:
    host(game *gameUI);
    ~host();

private:
    netserver *netServer;

public slots:
    void sendTest();
};

#endif // HOST_H
