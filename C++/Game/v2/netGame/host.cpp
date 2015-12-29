#include "host.h"
#include "game.h"

host::host(game *gameUI) : player(gameUI)
{
    ui->setLobbyInfoText("You are the host.");
//    netServer = new netserver;
//    netServer->StartServer();

//    qDebug() << "I'm hosting with a hand of: ";
//    info->Hand.PrintCards();
}

host::~host()
{
}

void host::sendTest()
{
//    cardstack cards;
//    cards.toStandardDeck();
//    netServer->SendToAll(message('C', "host to all", "Hamid", cards));
}

