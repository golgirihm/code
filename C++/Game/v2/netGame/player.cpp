#include "player.h"
#include "gameUI.h"

#include <QDebug>
#include <QHostAddress>

#define MIN_USERNAME_LENGTH 2
#define DEFAULT_CURRENTUSERNAME_TEXT ""





player::player(gameUI *parentUI)
{
    info = new playerinfo;
    info->ID = -1;
    info->userName = DEFAULT_CURRENTUSERNAME_TEXT;
    ui = parentUI;

    ui->set_l1_currentUsername(info->userName);
    ui->setEnabled_pb1_start(false);

    connect(this, SIGNAL(userNameChanged()), this, SLOT(pbLobbyAcceptEnabler()));
    connect(this, SIGNAL(userNameChanged()), this, SLOT(pbLobbyChangeUserNameEnabler()));
    connect(ui, SIGNAL(lobbyEnterUserNameTextChanged()), this, SLOT(pbLobbyChangeUserNameEnabler()));
    connect(ui, SIGNAL(lobbyNetworkTextChanged()), this, SLOT(pbLobbyAcceptEnabler()));
    connect(ui, SIGNAL(userNameChangeRequested()), this, SLOT(processSelfUserNameRequest()));
    connect(ui, SIGNAL(acceptSettingsClicked()), this, SLOT(acceptClicked()));

//    info->playerNumber = -1;
    ui->setFocus();
}

player::~player()
{

}

bool player::validUserName(QString userName)
{
    return userName.length() >= MIN_USERNAME_LENGTH;
}

void player::pbLobbyAcceptEnabler()
{
    /// grab data from ui
    QHostAddress IPAddress = ui->get_le1_IPAddress();
    int port = ui->get_le1_portNumber();

    /// handle accept button
    if(!IPAddress.toIPv4Address() || port > 65535 || port < 1024)
        ui->setEnabled_pb1_accept(false);
    else
        ui->setEnabled_pb1_accept(true);
}

void player::pbLobbyChangeUserNameEnabler()
{
    QString enteredName = ui->get_le1_enterUserName();

    /// handle change username button
    if(validUserName(enteredName) && (enteredName.compare(info->userName, Qt::CaseInsensitive)))
        ui->setEnabled_pb1_changeUserName(true);
    else
        ui->setEnabled_pb1_changeUserName(false);
}

void player::acceptClicked()
{
    ui->setEnabled_le1_IPAddress(false);
    ui->setEnabled_le1_portNumber(false);
    ui->setEnabled_pb1_accept(false);

}

void player::setUserName(QString newName)
{
    if(validUserName(newName))
    {
        info->userName = newName;
        ui->set_l1_currentUsername(info->userName);
        emit userNameChanged(); /// this is only for the server
    }
}
