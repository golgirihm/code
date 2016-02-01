#ifndef HOST_H
#define HOST_H

#include "player.h"
class netserver;

class QTimer; /// \todo REMOVE


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
    void processSelfUserNameRequest();
    void acceptClicked();
    void clientConnected(quint8 newID);
    void processReadyExternalData();
    void updateCurrentUsers();

private:
    bool uniqueValidUserName(QString newName);
    QString generateNewUserName(qint8 startID = 1);

    netserver *gameServer;

    GAMESTATE gameState;
    QList<playerinfo*> playerList;

signals:
    void playerListChanged();
};

#endif // HOST_H
