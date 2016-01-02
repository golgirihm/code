#include "guest.h"
#include "gameUI.h"
#include "netclient.h"
#include "message.h"

#define LOBBY_TEXT_G "Guest Lobby"
#define DEFAULT_ENTEREDUSERNAME_TEXT_G ""
#define LOBBYINFO1_TEXT_G "You are a guest.\n\nBe sure to enter the host's IP Address and port number correctly, and then accept the network settings."
#define LOBBYINFO2_TEXT_G "Attempting to connect to the host's IP Address and Port.\n\n . . ."
#define LOBBYINFO3_TEXT_G "Connected to the host.\n\nWaiting for the host to start the game . . ."


guest::guest(gameUI *parentUI) : player(parentUI)
{
    gameClient = new netclient;
    connect(gameClient, SIGNAL(externalDataReady()), this, SLOT(processReadyExternalData()));

    // TODO: REMOVE
    ui->setLobbyIPAddress(netComm::getLocalMachineIPv4().toString());
    ui->setLobbyPort(gameClient->getPort());

    initialLobbySetUp();
}

guest::~guest()
{

}

void guest::initialLobbySetUp()
{
    ui->setLobbyText(LOBBY_TEXT_G);
    ui->setLobbyInfoText(LOBBYINFO1_TEXT_G);
    ui->setLobbyEnterUserNameText(DEFAULT_ENTEREDUSERNAME_TEXT_G);

    ui->setLobbyIPAddressEnabled(true);
    ui->setLobbyPortEnabled(true);
    ui->setLobbyUserNameEnabled(false);
    pbLobbyAcceptEnabler();
    pbLobbyChangeUserNameEnabler();
}

void guest::pbLobbyAcceptEnabler()
{
    QHostAddress IPAddress = QHostAddress(ui->getLobbyIPAddressString());
    int port = ui->getLobbyPortString().toInt();

    if(gameClient->isConnected() || !IPAddress.toIPv4Address() || port > 65535 || port < 1024)
    {
        ui->setLobbyAcceptEnabled(false);
    }
    else
        ui->setLobbyAcceptEnabled(true);

}

void guest::pbLobbyChangeUserNameEnabler()
{
    QString newName = ui->getLobbyEnteredUserName();
    // handle change username button
    if(gameClient->isConnected() && validUserName(newName) && (newName != info->userName))
        ui->setLobbyChangeUserNameEnabled(true);
    else
        ui->setLobbyChangeUserNameEnabled(false);
}

void guest::processNewUserNameRequest()
{

    QString newName = ui->getLobbyEnteredUserName();

    if(gameClient->isConnected()) // if connected to server
    {
        // send message to host with new username
        gameClient->SendToServer( message(C::USERNAME_ASK, info->ID, newName) );
        // wait for message back with new name to set
    }
    else
    {
        setUserName(newName);
    }


}

void guest::ready()
{
    ui->setLobbyIPAddressEnabled(false);
    ui->setLobbyPortEnabled(false);
    ui->setLobbyAcceptEnabled(false);
    ui->setLobbyInfoText(LOBBYINFO2_TEXT_G);

    gameClient->setPort((quint16)ui->getLobbyPortString().toInt());
    gameClient->setIPv4(QHostAddress(ui->getLobbyIPAddressString()));
    gameClient->attemptToConnect();
}

void guest::processReadyExternalData()
{
    message msg(gameClient->receiveExternalData());

    qDebug() << "GUEST received message:" << msg.compressedString();


    // handle all communication from server here
    switch(msg.msgtype())
    {
    case S::USERNAME:
        setUserName(msg.text());
        info->ID = msg.extraData().at(0);
        ui->setLobbyUserNameEnabled(true);
        ui->setLobbyInfoText(LOBBYINFO3_TEXT_G);
        break;
    case S::LOBBYLIST:
        break;
    case S::OPEN_MAIN_GAME:
        break;
    }
}
