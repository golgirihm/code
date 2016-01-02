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

    enum GAMESTATE : quint8 {INITIAL_STATE, SERVER_STARTED, GUESTS_IN_LOBBY, GAME_STARTED};



signals:

public slots:

private slots:
    void initialLobbySetUp();
    void pbLobbyAcceptEnabler();
    void pbLobbyChangeUserNameEnabler();
    void processNewUserNameRequest();
    void ready();
    void clientConnected(quint8 newID);
    void processReadyExternalData();

private:
    netserver *gameServer;

    GAMESTATE gameState;
    QList<playerinfo*> guestList;
};

#endif // HOST_H
