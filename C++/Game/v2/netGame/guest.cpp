#include "guest.h"
#include "gameUI.h"
#include "netclient.h"
#include "message.h"

#define LOBBY_TEXT_G "Guest Lobby"
#define DEFAULT_ENTEREDUSERNAME_TEXT_G ""
#define LOBBYINFO1_TEXT_G "You are a guest.\n\nBe sure to enter the host's IP Address and port number correctly, and then accept the network settings."
#define LOBBYINFO2_TEXT_G "Attempting to connect to the host's IP Address and Port.\n\n . . ."
#define LOBBYINFO3_TEXT_G "Connected to the host.\n\nWaiting for the host to start the game . . ."

/// \todo REMOVE
#include <QPushButton>


guest::guest(gameUI *parentUI) : player(parentUI)
{
    gameClient = new netclient;
    connect(gameClient, SIGNAL(externalDataReady()), this, SLOT(processReadyExternalData()));

    /// \todo: REMOVE
    ui->set_le1_IPAddress(netComm::getLocalMachineIPv4());
    ui->set_le1_portNumber(gameClient->getPort());

    initialLobbySetUp();

    /// \todo REMOVE
    ui->get_pb1_accept()->animateClick();
}

guest::~guest()
{
    delete gameClient;
}

void guest::initialLobbySetUp()
{
    ui->set_l1_lobby(LOBBY_TEXT_G);
    ui->set_tb1_info(LOBBYINFO1_TEXT_G);
    ui->set_le1_enterUserName(DEFAULT_ENTEREDUSERNAME_TEXT_G);

    ui->setEnabled_le1_IPAddress(true);
    ui->setEnabled_le1_portNumber(true);
    ui->setEnabled_le1_enterUserName(false);

    pbLobbyAcceptEnabler();
    pbLobbyChangeUserNameEnabler();
}

void guest::pbLobbyAcceptEnabler()
{
    /// handle conditions specific to guest
    if(gameClient->isConnected())
        ui->setEnabled_pb1_accept(false);
    /// if special conditions don't occur, use parent handler
    else
        player::pbLobbyAcceptEnabler();
}

void guest::pbLobbyChangeUserNameEnabler()
{
    /// handle conditions specific to guest
    if(!gameClient->isConnected() || !validUserName(ui->get_le1_enterUserName()))
        ui->setEnabled_pb1_changeUserName(false);
    /// if special conditions don't occur, use parent handler
    else
        player::pbLobbyChangeUserNameEnabler();
}

void guest::processSelfUserNameRequest()
{
    /// if connected to server
    if(gameClient->isConnected())
    {
        /// ask host for new username
        gameClient->SendToServer( message(C::USERNAME_ASK, info->ID, ui->get_le1_enterUserName()) );
        /// wait for message back with new name to set

    }

}

void guest::acceptClicked()
{
    ui->set_tb1_info(LOBBYINFO2_TEXT_G);

    gameClient->setPort(static_cast<quint16>(ui->get_le1_portNumber()));
    gameClient->setIPv4(ui->get_le1_IPAddress());
    gameClient->attemptToConnect();

    /// call parent behavior as well
    player::acceptClicked();
}

void guest::processReadyExternalData()
{
    message msg(gameClient->receiveExternalData());

    if(msg.senderID() != HOSTID)
    {
        qDebug() << "ERROR: client received a message from an unknown (non-host) sender. Ignoring message.";
        return;
    }


    /// handle all communication from server here
    switch(msg.msgtype())
    {
    case S::START_INFO:
        setUserName(msg.text());
        info->ID = msg.extraData().at(0);
        ui->setEnabled_le1_enterUserName(true);
        ui->set_tb1_info(LOBBYINFO3_TEXT_G);
        break;
    case S::USERNAME:
        setUserName(msg.text());
        break;
    case S::LOBBY_USERS:
    {
//        QStringList names = msg.text().split(MSG_USERNAME_DELIMITER, QString::SkipEmptyParts);
        ui->set_tb1_currentUsers(QString(msg.text()).replace(MSG_USERNAME_DELIMITER, LOCAL_USERNAME_DELIMITER));
        qDebug() << "Made it to LOBBY_USERS case";
        break;
    }
    case S::USERNAME_TAKEN:
        qDebug() << "GUEST: username not currently available (host reported).";
        break;
    case S::LOBBYLIST:
        break;
    case S::OPEN_MAIN_GAME:
        break;
    }

    qDebug() << "GUEST #" << info->ID << "received :" << msg.compressedString();
}
