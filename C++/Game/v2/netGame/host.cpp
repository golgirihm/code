#include "host.h"
#include "gameUI.h"
#include "netserver.h"
#include "message.h"

#define LOBBY_TEXT_H "Host Lobby"
#define DEFAULT_ENTEREDUSERNAME_TEXT_H "hostPlayer"
#define LOBBYINFO1_TEXT_H "You are the host. \n\nPlease enter a username, accept the network settings, and give your IP address and Port number to anyone who wants to join."
#define LOBBYINFO2_TEXT_H "Server started.\n\nCurrently waiting for clients to join.\n\n . . ."
#define LOBBYINFO3_TEXT_H "You may now click start to begin the game, or wait for more clients to join."

#define BASENAME "client"

#include <QPushButton> /// \todo REMOVE
#include <QThread>

host::host(gameUI *parentUI) : player(parentUI)
{
    info->ID = HOSTID;

    gameServer = new netserver;
    connect(gameServer, SIGNAL(clientAdded(quint8)), this, SLOT(clientConnected(quint8)));
    connect(gameServer, SIGNAL(externalDataReady()), this, SLOT(processReadyExternalData()));

    /// display the IP Address of this machine--found with the netServer class--and default port
    ui->set_le1_IPAddress(netComm::getLocalMachineIPv4());
    ui->set_le1_portNumber(gameServer->getPort());

    /// let the host be element 0 of the player list
    playerList.append(info);

    connect(this, SIGNAL(playerListChanged()), this, SLOT(updateCurrentUsers()));


    gameState = GAMESTATE::INITIAL_STATE;
    initialLobbySetUp();

    /// \todo REMOVE
//    ui->get_pb1_changeUserName()->click();
//    ui->get_pb1_accept()->animateClick();

}

host::~host()
{
    delete gameServer;
}


void host::initialLobbySetUp()
{
    ui->set_l1_lobby(LOBBY_TEXT_H);
    ui->set_tb1_info(LOBBYINFO1_TEXT_H);
    ui->set_le1_enterUserName(DEFAULT_ENTEREDUSERNAME_TEXT_H);

    ui->setEnabled_le1_IPAddress(false);
    ui->setEnabled_le1_portNumber(true);
    ui->setEnabled_le1_enterUserName(true);

    pbLobbyAcceptEnabler();
    pbLobbyChangeUserNameEnabler();
}

void host::pbLobbyAcceptEnabler()
{
    /// handle conditions specific to host
    if(gameServer->isListening() || !validUserName(info->userName))
        ui->setEnabled_pb1_accept(false);
    /// if special conditions don't occur, use parent handler
    else
        player::pbLobbyAcceptEnabler();
}

void host::pbLobbyChangeUserNameEnabler()
{
    /// handle conditions specific to host
    if(!uniqueValidUserName(ui->get_le1_enterUserName()))
        ui->setEnabled_pb1_changeUserName(false);
    /// if special conditions don't occur, use parent handler
    else
        player::pbLobbyChangeUserNameEnabler();
}

void host::processSelfUserNameRequest()
{
    QString desiredName = ui->get_le1_enterUserName();
    /// check if username is good
    if(uniqueValidUserName(desiredName))
    {
        setUserName(desiredName);

        if(gameState != INITIAL_STATE && gameState != SERVER_STARTED) // if connected to any clients
        {
            // send message to all connected clients
            emit playerListChanged();
        }
    }
    else
        qDebug() << "could not change server's username to" << desiredName << "since it already exists or is invalid.";
}

void host::acceptClicked()
{
    ui->set_tb1_info(LOBBYINFO2_TEXT_H);

    /// set up and start the server
    gameServer->setPort(static_cast<quint16>(ui->get_le1_portNumber()));
    gameServer->setIPv4(ui->get_le1_IPAddress());
    gameServer->StartServer();

    gameState = GAMESTATE::SERVER_STARTED;

    /// call parent behavior as well
    player::acceptClicked();
}

void host::clientConnected(quint8 newID)
{
    gameState = GAMESTATE::GUESTS_IN_LOBBY;
    ui->setEnabled_pb1_start(true);
    ui->set_tb1_info(LOBBYINFO3_TEXT_H);
    playerinfo *newPlayer = new playerinfo;
    newPlayer->ID = newID;
    newPlayer->userName = generateNewUserName(newPlayer->ID);
    playerList.append(newPlayer);

    qDebug() << "SERVER: clientConnected() sending starter info to client number " << playerList.indexOf(newPlayer);
    gameServer->SendToClient( message(S::START_INFO, HOSTID, newPlayer->userName, QByteArray().append(newPlayer->ID)), newPlayer->ID );

    /// \todo: revisit this... seems like it is working but not sure
    // TESTING socket handling/timing:
    emit playerListChanged();

    if(playerList.indexOf(newPlayer) != newID)
        qDebug() << "HOST: WARNING -- playerList.indexof(newPlayer) != newID sent from netServer!!!";
}

void host::processReadyExternalData()
{
    message msg(gameServer->receiveExternalData());

    qDebug() << "HOST received:" << msg.compressedString();

    /// handle all communication from clients here
    switch(msg.msgtype())
    {
    case C::USERNAME_ASK:
    {
        QString newClientName = msg.text();
        if(uniqueValidUserName(newClientName))
        {
            playerList.at(msg.senderID())->userName = newClientName;
            gameServer->SendToClient( message(S::USERNAME, HOSTID, newClientName), msg.senderID() );
            emit playerListChanged();
        }
        else
        {
            qDebug() << "Letting client know their username request was rejected.";
            gameServer->SendToClient( message(S::USERNAME_TAKEN, HOSTID), msg.senderID() );
        }
        break;
    }
    case C::CHATMESSAGE:
        break;
    }
}

void host::updateCurrentUsers()
{
    QString currentUsers;
    foreach(playerinfo *info_it, playerList)
        currentUsers += info_it->userName + MSG_USERNAME_DELIMITER;

    /// send new list of players to all clients
    qDebug() << "SERVER: updateCurrentUsers now sending all clients updated currentUsers text.";
    gameServer->SendToAllClients( message(S::LOBBY_USERS, HOSTID, currentUsers) );

    /// update locally
    ui->set_tb1_currentUsers(currentUsers.replace(MSG_USERNAME_DELIMITER, LOCAL_USERNAME_DELIMITER));
}

bool host::uniqueValidUserName(QString newName)
{
    foreach(playerinfo *info_it, playerList)
    {
//        qDebug() << "uniqueValidUserName: comparing " << newName << "and" << info_it->userName;
        if(!newName.compare(info_it->userName, Qt::CaseInsensitive) || !validUserName(newName))
            return false;
    }
    return true;
}

QString host::generateNewUserName(qint8 startID)
{
    QString newName;
    int nameNumber = startID;

    do
    {
        newName = QString(BASENAME) + QString::number(nameNumber);
    } while(!uniqueValidUserName(newName));

    return newName;

}

