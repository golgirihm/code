#include "host.h"
#include "gameUI.h"
#include "netserver.h"
#include "message.h"

#define LOBBY_TEXT_H "Host Lobby"
#define DEFAULT_ENTEREDUSERNAME_TEXT_H "hostPlayer"
#define LOBBYINFO1_TEXT_H "You are the host. \n\nPlease enter a username, accept the network settings, and give your IP address and Port number to anyone who wants to join."
#define LOBBYINFO2_TEXT_H "Server started.\n\nCurrently waiting for clients to join.\n\n . . ."
#define LOBBYINFO3_TEXT_H "You may now click start to begin the game, or wait for more clients to join."

host::host(gameUI *parentUI) : player(parentUI)
{
    info->ID = HOSTID;

    gameServer = new netserver;
    connect(gameServer, SIGNAL(clientAdded(quint8)), this, SLOT(clientConnected(quint8)));
    connect(gameServer, SIGNAL(externalDataReady()), this, SLOT(processReadyExternalData()));

    // display the IP Address of this machine--found with the netServer class--and default port
    ui->setLobbyIPAddress(netComm::getLocalMachineIPv4().toString());
    ui->setLobbyPort(gameServer->getPort());

    gameState = GAMESTATE::INITIAL_STATE;
    initialLobbySetUp();
}

host::~host()
{

}


void host::initialLobbySetUp()
{
    ui->setLobbyText(LOBBY_TEXT_H);
    ui->setLobbyInfoText(LOBBYINFO1_TEXT_H);
    ui->setLobbyEnterUserNameText(DEFAULT_ENTEREDUSERNAME_TEXT_H);

    ui->setLobbyIPAddressEnabled(false);
    ui->setLobbyPortEnabled(true);
    ui->setLobbyUserNameEnabled(true);
    pbLobbyAcceptEnabler();
    pbLobbyChangeUserNameEnabler();
}

void host::pbLobbyAcceptEnabler()
{
    QHostAddress IPAddress = QHostAddress(ui->getLobbyIPAddressString());
    int port = ui->getLobbyPortString().toInt();

    // handle accept button
    if(gameServer->isListening() || !IPAddress.toIPv4Address() || port > 65535 || port < 1024 || !validUserName(info->userName))
        ui->setLobbyAcceptEnabled(false);
    else
        ui->setLobbyAcceptEnabled(true);

}

void host::pbLobbyChangeUserNameEnabler()
{
    QString newName = ui->getLobbyEnteredUserName();

    // handle change username button
    if(validUserName(newName) && (newName != info->userName))
        ui->setLobbyChangeUserNameEnabled(true);
    else
        ui->setLobbyChangeUserNameEnabled(false);
}

void host::processNewUserNameRequest()
{
    // TODO: implement this function

    // check if username is unique in list of players

    if(gameState == GUESTS_IN_LOBBY) // if connected to any clients
    {
        // send message to all connected clients


    }
    else if((gameState == INITIAL_STATE) || (gameState == SERVER_STARTED))
    {
        setUserName(ui->getLobbyEnteredUserName());
    }
}

void host::ready()
{
    ui->setLobbyInfoText(LOBBYINFO2_TEXT_H);
    ui->setLobbyIPAddressEnabled(false);
    ui->setLobbyPortEnabled(false);
    ui->setLobbyAcceptEnabled(false);

    gameServer->setPort((quint16)ui->getLobbyPortString().toInt());
    gameServer->setIPv4(QHostAddress(ui->getLobbyIPAddressString()));
    gameServer->StartServer();

    gameState = GAMESTATE::SERVER_STARTED;
}

void host::clientConnected(quint8 newID)
{
    gameState = GAMESTATE::GUESTS_IN_LOBBY;
    ui->setLobbyStartEnabled(true);
    ui->setLobbyInfoText(LOBBYINFO3_TEXT_H);
    playerinfo *newPlayer = new playerinfo;
    newPlayer->ID = newID;
    newPlayer->userName = "client0"; // TODO: make a generateNewUsername() function
    guestList.append(newPlayer);

    qDebug() << "SERVER: Client connected, sending starter info to client number " << guestList.indexOf(newPlayer);
//    temp->append(newPlayer->ID);
    qDebug() << QByteArray().append((char) 0);

    gameServer->SendToClient( message(S::USERNAME, info->ID, newPlayer->userName, QByteArray().append((char)newPlayer->ID)), newPlayer->ID );

    // TODO: LEFT OFF HERE!!!!!
    if(guestList.indexOf(newPlayer) != newID)
        qDebug() << "HOST: WARNING -- guestList.indexof(newPlayer) != newID sent from netServer!!!";

}

void host::processReadyExternalData()
{
    message msg(gameServer->receiveExternalData());

    qDebug() << "HOST received message:" << msg.compressedString();

    // handle all communication from clients here
    switch(msg.msgtype())
    {
    case C::USERNAME_ASK:
        gameServer->SendToClient( message(S::USERNAME, info->ID, msg.text()), msg.senderID() );
        break;
    case C::CHATMESSAGE:
        break;
    }
}
