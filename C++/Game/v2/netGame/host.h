#ifndef HOST_H
#define HOST_H

#include "player.h"
class netserver;

class host : public player
{
    Q_OBJECT

public:
    host(gameUI *parentUI);
    ~host();

    enum GAMESTATE : quint8 {INITIAL_STATE, SERVER_STARTED, GUESTS_CONNECTED, GAME_STARTED};

signals:

public slots:

private slots:
    void initialLobbySetUp();
    void PBLobbyAcceptEnabler();
    void PBLobbyChangeUserNameEnabler();
    void processNewUserNameRequest();
    void ready();
    void clientConnected();
    void processReceivedData();


private:
    netserver *gameServer;

    QList<playerinfo> guestList;

};

#endif // HOST_H
