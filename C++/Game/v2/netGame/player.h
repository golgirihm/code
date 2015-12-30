#ifndef PLAYER_H
#define PLAYER_H

class gameUI;
class netcomm;
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
    player(gameUI *parentUI);
    ~player();

    bool validUserName(QString userName);

signals:
    void userNameChanged();

public slots:

protected slots:
    virtual void initialLobbySetUp() = 0;
    virtual void PBLobbyAcceptEnabler() = 0;
    virtual void PBLobbyChangeUserNameEnabler() = 0;
    virtual void processNewUserNameRequest() = 0;
    virtual void ready() = 0;
    virtual void processReceivedData() = 0;
    void setUserName(QString newName);

protected:
    gameUI *ui;
//    netcomm *gameComm;
    playerinfo *info;





};

#endif // PLAYER_H
