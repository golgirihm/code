#ifndef GUEST_H
#define GUEST_H

#include "player.h"
class netclient;

class guest : public player
{
    Q_OBJECT

public:
    guest(gameUI *parentUI);
    ~guest();

signals:

public slots:

private slots:
    void initialLobbySetUp();
    void pbLobbyAcceptEnabler();
    void pbLobbyChangeUserNameEnabler();
    void processSelfUserNameRequest();
    void acceptClicked();
    void processReadyExternalData();

private:
    netclient *gameClient;

};

#endif // GUEST_H
