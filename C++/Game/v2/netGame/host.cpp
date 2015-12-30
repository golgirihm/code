#include "host.h"
#include "player.h"
#include "gameUI.h"
#include "netserver.h"
#include "message.h"

#define LOBBY_TEXT_H "Host Lobby"
#define DEFAULT_ENTEREDUSERNAME_TEXT_H "hostPlayer"
#define LOBBYINFO1_TEXT_H "You are the host. \n\nPlease enter a username, accept the network settings, and give your IP Address and Port number to anyone who wants to join."
#define LOBBYINFO2_TEXT_H "Server started.\n\nCurrently waiting for clients to join.\n\n . . ."
#define LOBBYINFO3_TEXT_H "Server started. You may now click start, or wait for more clients to join."

host::host(gameUI *parentUI) : player(parentUI)
{
    gameServer = new netserver;
    connect(gameServer, SIGNAL(clientAdded()), this, SLOT(clientConnected()));
    connect(gameServer, SIGNAL(externalDataReady()), this, SLOT(processReceivedData()));

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
    // check if username is unique in list of players

    if(0) // if connected to any clients
    {
        // send message to all connected clients

    }
    else
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

void host::clientConnected()
{
    ui->setLobbyInfoText(LOBBYINFO3_TEXT_H);
    playerinfo newPlayer;
    newPlayer.userName = "client1";

    qDebug() << "SERVER: Client connected, sending message to" << gameServer->ClientCount() << "clients.";
    gameServer->SendToAllClients(message(1,newPlayer.userName));
    ui->setLobbyStartEnabled(true);

    gameState = GAMESTATE::GUESTS_CONNECTED;
}

void host::processReceivedData()
{

}
