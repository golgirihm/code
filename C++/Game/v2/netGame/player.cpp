#include "player.h"
#include "gameUI.h"
#include "cardstack.h"

#include <QDebug>

#define MIN_USERNAME_LENGTH 2
#define DEFAULT_CURRENTUSERNAME_TEXT ""

player::player(gameUI *parentUI)
{
    info = new playerinfo;

    ui = parentUI;
    info->userName = DEFAULT_CURRENTUSERNAME_TEXT;
    ui->setLobbyCurrentUserName(info->userName);
    ui->setLobbyStartEnabled(false);

    connect(this, SIGNAL(userNameChanged()), this, SLOT(pbLobbyChangeUserNameEnabler()));
    connect(this, SIGNAL(userNameChanged()), this, SLOT(pbLobbyAcceptEnabler()));
    connect(ui, SIGNAL(lobbyNetworkTextChanged()), this, SLOT(pbLobbyAcceptEnabler()));
    connect(ui, SIGNAL(lobbyEnterUserNameTextChanged()), this, SLOT(pbLobbyChangeUserNameEnabler()));
    connect(ui, SIGNAL(userNameChangeRequested()), this, SLOT(processNewUserNameRequest()));
    connect(ui, SIGNAL(acceptSettingsClicked()), this, SLOT(ready()));

//    info->playerNumber = -1;
    ui->setFocus();
}

player::~player()
{
    delete info;
}

bool player::validUserName(QString userName)
{
    return userName.length() >= MIN_USERNAME_LENGTH;
}

void player::setUserName(QString newName)
{
    if(validUserName(newName))
    {
        info->userName = newName;
        ui->setLobbyCurrentUserName(info->userName);
        emit userNameChanged();
    }
}
