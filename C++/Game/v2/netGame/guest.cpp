#include "guest.h"
//#include "player.h"
#include "game.h"
#include "netclient.h"

guest::guest(game *gameUI) : player(gameUI)
{
    ui->setLobbyInfoText("You are a guest.");
//    ui->setLobbyInfoText("You are a guest.");
    netClient = new netclient;
    netClient->attemptToConnect();
//    qDebug() << "Guest hand: ";
//    info->Hand.PrintCards();
}

guest::~guest()
{

}

void guest::sendTest()
{
//    cardstack cards;
//    cards.toStandardDeck();
//    netClient->SendToServer(message('C', "guest to host", "Hamid", cards));
}

