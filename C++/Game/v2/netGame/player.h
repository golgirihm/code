#ifndef PLAYER_H
#define PLAYER_H

#define MSG_USERNAME_DELIMITER ','
#define LOCAL_USERNAME_DELIMITER '\n'

class gameUI;
class netcomm;
#include "cardstack.h"

#include <QDebug>

#define HOSTID 0x80

namespace S
{   // from-server message types
    enum S_t : quint8
    {
        START_INFO = 'S',
        USERNAME = 'U',
        LOBBY_USERS = 'B',
        USERNAME_TAKEN = 'T',
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
        USERNAME_ASK = 'A',
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
        qint8 ID;
        QString userName;
        cardstack Hand;
    };

    static bool validUserName(QString userName);

public slots:

protected slots:
    virtual void initialLobbySetUp() = 0;
    virtual void pbLobbyAcceptEnabler();
    virtual void pbLobbyChangeUserNameEnabler();
    virtual void processSelfUserNameRequest() = 0;
    virtual void acceptClicked();
    virtual void processReadyExternalData() = 0;
    void setUserName(QString newName);

protected:
    gameUI *ui;
//    netcomm *gameComm;
    playerinfo *info;

signals:
    void userNameChanged();



};

#endif // PLAYER_H
