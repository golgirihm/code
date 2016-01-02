#ifndef PLAYER_H
#define PLAYER_H

class gameUI;
class netcomm;
#include "cardstack.h"

#include <QDebug>

#define HOSTID 0xFF

namespace S
{   // from-server message types
    enum S_t : quint8
    {
        USERNAME = 'U',
        LOBBYLIST = 'L',
        OPEN_MAIN_GAME = 'O',
//        CHATMESSAGE = 'M',
//        CARD_FOR_HAND = 'C',
//        PLAYERS_STATUS = 'P',
//        DECK_COUNT = 'D',
//        PLAYED_CARD = 'T'
    };
}

namespace C
{   // from-client message types
    enum C_t : quint8
    {
        USERNAME_ASK = 'U',
        CHATMESSAGE = 'Q',
//        CARD_TO_PLAY = 'C'
    };
}


class player : public QObject
{
    Q_OBJECT

public:
    player(gameUI *parentUI);
    ~player();

    // lightweight helper class for players
    class playerinfo
    {
    public:
        quint8 ID;
        QString userName;
        cardstack Hand;
    };



    static bool validUserName(QString userName);

signals:
    void userNameChanged();

public slots:

protected slots:
    virtual void initialLobbySetUp() = 0;
    virtual void pbLobbyAcceptEnabler() = 0;
    virtual void pbLobbyChangeUserNameEnabler() = 0;
    virtual void processNewUserNameRequest() = 0;
    virtual void ready() = 0;
    virtual void processReadyExternalData() = 0;
    void setUserName(QString newName);

protected:
    gameUI *ui;
//    netcomm *gameComm;
    playerinfo *info;




};

#endif // PLAYER_H
