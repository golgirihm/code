#include "game.h"
#include "ui_game.h"

#include "Communications\net_server.h"
#include "Communications\net_client.h"
#include "Communications\message.h"

#include "Forms_Code\lobby.h"
#include "Forms_Code\mainscreen.h"

#include "card.h"
#include "cardstack.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    connect(ui->bg_mainmenu, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(process_opening_screen_button_click(QAbstractButton*)));

    GameServer = 0;
    GameClient = 0;
    GameLobby = 0;

    UserName = "";

//    card fakecard(ACE, SPADES);
//    cardstack fakecardstack;
//    fakecardstack.ToStandardDeck();
//    //    qDebug() << "sizeof cardstack ==" << sizeof(cardstack);

//    //    for(int j = 0; j < 1; j++)
//    //    {
//    //        for(unsigned char i = 49; i < 50; ++i)
//    //        {
//    QByteArray buffer;
//    message msg1(C::LOBBYTEXT, "1234567890", "1234567890", fakecardstack);

//    buffer = msg1.bytes();
//    message msg2(buffer);

//    qDebug() << "msg1 == " << msg1.msgtype() << msg1.text() << msg1.from() << msg1.cards().CompressedString();
//    qDebug() << "msg2 == "  << msg2.msgtype() << msg2.text() << msg2.from() << msg2.cards().CompressedString();

//    if(msg2.msgtype() != msg1.msgtype())
//        qDebug() << "msgtype error";
//    if(msg2.text() != msg1.text())
//        qDebug() << "text error";
//    if(msg2.from() != msg1.from())
//        qDebug() << "from error";
//    if(msg2.cards().TopCard().CompressedString() != msg1.cards().TopCard().CompressedString())
//        qDebug() << "cardstack string error";

    //        }
    //    }

}

game::~game()
{
    //    qDebug() << "~game()";
    delete ui;
}

void game::process_opening_screen_button_click(QAbstractButton* ClickedButton)
{
    if(ClickedButton == ui->pb_joingame)
    {
        // player is now a client
        qDebug() << "CLIENT";
        PlayerType = CLIENT;

        // allocate memory for a lobby window
        GameLobby = new lobby(PlayerType, this);

        // handle user interaction with lobby
        connect(GameLobby, SIGNAL(TextChanged()), this, SLOT(lobby_pb_handler()));
        connect(GameLobby, SIGNAL(ClientAcceptClicked()), this, SLOT(client_ready()));

        // close previous window and open lobby
        GameLobby->setAcceptButton(true); // TODO: remove this
        GameLobby->show();
        this->hide();
    }
    else if(ClickedButton == ui->pb_hostgame)
    {
        // player is now a server
        qDebug() << "SERVER";
        PlayerType = SERVER;

        // number of cards == 0, player number == 0 for server
        playerinfo Server_Player = {UserName, 0, cardstack()};

        // add server as player number 0
        if(!PlayerList.length())
            PlayerList.append(Server_Player);

        // start the server immediately upon clicking host button
        GameServer = new net_server(this);
        GameServer->StartServer();

        // whenever the server has receives something, process it
        connect(GameServer, SIGNAL(ExternalDataReady()), this, SLOT(server_process_external_data()));

        // allocate memory for a lobby window
        GameLobby = new lobby(PlayerType, this);
        GameLobby->set_l_your_ip_val(GameServer->getServerIP().toString());
        GameLobby->set_l_port_number(GameServer->getServerPort());

        // handle user interaction with lobby
        connect(GameLobby, SIGNAL(TextChanged()), this, SLOT(lobby_pb_handler()));
        connect(GameLobby, SIGNAL(ServerAcceptClicked()), this, SLOT(server_ready()));
        connect(GameLobby, SIGNAL(StartGameClicked()), this, SLOT(start_game()));

        // close previous window and open lobby
        GameLobby->setAcceptButton(true); // TODO: remove this
        GameLobby->show();
        this->hide();
    }
}

void game::lobby_pb_handler()
{
    // if there is invalid information on the lobby window
    if(GameLobby->get_username().simplified().length() < 2
            || (PlayerType == CLIENT && (!GameLobby->get_le_host_ip().toIPv4Address() || GameLobby->get_le_host_port() > 65535 || GameLobby->get_le_host_port() < 1024)))
    {
        GameLobby->setAcceptButton(false);
    }
    // all information on lobby window is valid
    else
    {
        GameLobby->setAcceptButton(true);
        GameLobby->setStartButton(false);
    }
}

// client function
void game::client_ready()
{
    QString LobbyName = GameLobby->get_username().simplified();


    // if client socket has not been created
    if(GameClient == 0)
    {
        // allocate memory for client socket
        GameClient = new net_client(this);

        // take action when connection is made, and process data when it is available
        connect(GameClient, SIGNAL(ConnectionMade()), this, SLOT(client_connected()));
        connect(GameClient, SIGNAL(ExternalDataReady()), this, SLOT(client_process_external_data()));

        // try to connect to the server
        GameClient->setHostInfo(GameLobby->get_le_host_ip(), GameLobby->get_le_host_port());
        GameClient->attemptToConnect();

        // do not allow changing of the ip address and port after trying to connect
        GameLobby->set_le_host_ip_enabled(false);
        GameLobby->set_le_host_port_enabled(false);

        UserName = LobbyName;
    }
    // if client wants to change their username
    else if(GameClient->isConnected() && LobbyName != UserName)
    {
        // new username request
        message msg(S::USERNAME, LobbyName, UserName);
        GameClient->SendToServer(msg.bytes());
    }

    // confirmation to the user, and prevention of unnecessary clicks
    GameLobby->setAcceptButton(false);
}

// server function
void game::server_ready()
{
    QString oldName = UserName;
    UserName = GameLobby->get_username().simplified();

    // prevents duplicate information
    if(UserName != oldName)
    {
        // update local lobby text
        QString LobbyString = UserName + " is the host.";
        GameLobby->append_users_joined_text(LobbyString);

        // send entire lobby text to all clients
        message msg(C::LOBBYTEXT, GameLobby->get_users_joined_text());
        GameServer->SendToAllClients(msg.bytes());

        // update player list
        PlayerList[0].UserName = UserName;
    }

    // prevent user from clicking accept again
    GameLobby->setAcceptButton(false);
    GameLobby->setStartButton(true);
}

// client function
void game::client_connected()
{
    qDebug() << "Sending message to server: message msg(S::USERNAME, NO_STRING, " << UserName << ")";

    // send username to server on connection
    message msg(S::USERNAME, NO_STRING, UserName);
    GameClient->SendToServer(msg.bytes());
}

// server function
void game::server_process_external_data()
{
    // convert bytes to a message object
    message msg_r(GameServer->ReceiveExternalData());

    QString debugstring = "Server received message: ";

    switch(msg_r.msgtype().toLatin1())
    {

    // a client has joined or changed their name and notified the server
    case S::USERNAME:
    {
        debugstring += "S::USERNAME";
        QString LobbyString;
        QString OldName, NewName;

        if(msg_r.text() == NO_STRING)
        {
            // NewName is the first username that the client sent
            NewName = msg_r.from();

            // new player joined
            LobbyString = NewName + " has joined.";

            // create new player
            playerinfo NewPlayer = {NewName, PlayerList.length(), cardstack()};

            // add player's name to master list of players
            PlayerList.append(NewPlayer);
        }
        else
        {
            // not the first time the client sent a username
            OldName = msg_r.from();
            NewName = msg_r.text();

            // user has changed name
            LobbyString = OldName + " changed name to " + NewName;

            // TODO: change name in PlayerList here
            qDebug() << "Warning: name not actually changed, need to update code";
        }

        // add text to server's lobby
        GameLobby->append_users_joined_text(LobbyString);

        // send entire lobby text to all clients
        message msg(C::LOBBYTEXT, GameLobby->get_users_joined_text());
        GameServer->SendToAllClients(msg.bytes());
    }
        break;

        // a client or the server (self) has sent a message to the chatroom
    case S::CHATMESSAGE:
    {
        debugstring += "S::CHATMESSAGE";
        QString ChatMessage = "<" + msg_r.from() + "> " + msg_r.text();

        // put chat in server's chatbox
        GameWnd->AppendToChatRoom(ChatMessage);

        // forward to all clients
        message msg(C::CHATMESSAGE, ChatMessage);
        GameServer->SendToAllClients(msg.bytes());
    }
        break;
    }

        qDebug() << debugstring;
}

// client function
void game::client_process_external_data()
{
    message msg_r(GameClient->ReceiveExternalData());
    QString debugstring = "received: ";

    switch(msg_r.msgtype().toLatin1())
    {
    case C::LOBBYTEXT:
    {
        debugstring += "C::LOBBYTEXT";
        GameLobby->set_users_joined_text(msg_r.text());
    }
        break;
    case C::OPEN_MAIN_GAME:
    {
        debugstring += "C::OPEN_MAIN_GAME";
        GameLobby->hide();
        GameWnd = new mainscreen(this);
        GameWnd->show();
        GameWnd->setUserName(UserName + " (client)");
        connect(GameWnd, SIGNAL(ChatMessageReady()), this, SLOT(SendToChatroom()));

        // TODO: comment in
        //        Hand = new cardstack(this);
//        connect(Hand, SIGNAL(StackChanged(cardstack*)), GameWnd, SLOT(SetHand(cardstack*)));
    }
        break;
    case C::CARD_FOR_HAND:
    {
        debugstring += "CARD_FOR_HAND: " + msg_r.cards().TopCard().CompressedString();
        Hand->AddCard(msg_r.cards().TopCard());
        GameWnd->SetHand(Hand);
    }
        break;
    case C::CHATMESSAGE:
    {
        debugstring += "C::CHATMESSAGE";
        GameWnd->AppendToChatRoom(msg_r.text());
    }
        break;
    case C::PLAYERS_STATUS:
    {
        debugstring += "C::PLAYERS_STATUS";
        GameWnd->SetPlayersStatus(msg_r.text());
    }
        break;
    case C::DECK_COUNT:
    {
        debugstring += "C::DECK_COUNT " + msg_r.text();
        GameWnd->SetDeckCount(msg_r.text().toInt());
    }
        break;
    case C::PLAYED_CARD:
    {
        debugstring += "C::PLAYED_CARD " + msg_r.cards().TopCard().CompressedString();
        GameWnd->SetPlayedCard(msg_r.cards().TopCard());
    }
        break;
    default:
        qDebug() << "not recognized";
    } // switch

    if(msg_r.msgtype() != C::PLAYERS_STATUS && msg_r.msgtype() != C::PLAYED_CARD && msg_r.msgtype() != C::DECK_COUNT)
        qDebug() << debugstring;
}

// server function
void game::start_game()
{
    GameServer->CloseOffServer();

    GameLobby->hide();
    GameWnd = new mainscreen(this);
    GameWnd->show();
    GameWnd->setUserName(UserName + " (host)");
    connect(GameWnd, SIGNAL(ChatMessageReady()), this, SLOT(SendToChatroom()));

    message msg(C::OPEN_MAIN_GAME);
    GameServer->SendToAllClients(msg.bytes());

    Hand = new cardstack(this);
    connect(Hand, SIGNAL(StackChanged(cardstack*)), GameWnd, SLOT(SetHand(cardstack*)));

    MainDeck = new cardstack(this);
    MainDeck->ToStandardDeck();
    //    connect(MainDeck, SIGNAL(StackChanged(cardstack*)), this, SLOT(UpdateDeckCount()));

    PlayedCards = new cardstack(this);
    //    connect(PlayedCards, SIGNAL(StackChanged(cardstack*)), this, SLOT(UpdatePlayedCard()));

    this->deal();
    PlayedCards->AddCard(MainDeck->TakeTopCard());

    UpdateTimer1 = new QTimer(this);
    UpdateTimer2 = new QTimer(this);
    UpdateTimer3 = new QTimer(this);
    connect(UpdateTimer1, SIGNAL(timeout()), this, SLOT(UpdatePlayedCard()));
    connect(UpdateTimer2, SIGNAL(timeout()), this, SLOT(UpdateDeckCount()));
    connect(UpdateTimer3, SIGNAL(timeout()), this, SLOT(UpdatePlayersStatus()));
        UpdateTimer1->start(UPDATE_INTERVAL);
        UpdateTimer2->start(UPDATE_INTERVAL);
        UpdateTimer3->start(UPDATE_INTERVAL);

}

void game::SendToChatroom()
{
    // message to send to all
    QString ChatMessage = GameWnd->GetChatInput();

    // check if the message is empty
    if(ChatMessage.isEmpty())
        return;

    // clear input upon sending
    GameWnd->ClearChatInput();

    // ChatMessage and Username correspond to the player who called SendToChatroom()
    message msg(S::CHATMESSAGE, ChatMessage, UserName);

    // send to the server so that server can forward, even if server is self
    switch(PlayerType)
    {
    case CLIENT:
        GameClient->SendToServer(msg.bytes());
        break;
    case SERVER:
        GameServer->SendToSelf(msg.bytes());
        break;
    }
}

// server function
void game::UpdatePlayersStatus()
{
    // get the new string
    int NumberOfPlayers = PlayerList.length();

    QString PlayersDisplay;
    for(int i = 0; i < NumberOfPlayers; ++i)
        PlayersDisplay += PlayerList[i].UserName + "\t" + QString::number(PlayerList[i].Hand.NumberOfCards()) + " cards\n";

    // update locally
    GameWnd->SetPlayersStatus(PlayersDisplay);

    // inform all clients
    //    qDebug() << "sending C::PLAYERS_STATUS message";
    message msg(C::PLAYERS_STATUS, PlayersDisplay);
    GameServer->SendToAllClients(msg.bytes());
}

// server function
void game::UpdateDeckCount()
{
    // find the value
    int NumDeckCards = MainDeck->NumberOfCards();

    // update locally
    GameWnd->SetDeckCount(NumDeckCards);

    // inform all clients
    //    qDebug() << "sending C::DECK_COUNT message";
    message msg(C::DECK_COUNT, QString::number(NumDeckCards));
    GameServer->SendToAllClients(msg.bytes());
}

void game::UpdatePlayedCard()
{
    // find the value
    card PlayedCard(PlayedCards->TopCard());

    // update locally
    GameWnd->SetPlayedCard(PlayedCard);

    // inform all clients
    //    qDebug() << "sending C::PLAYED_CARD message";
    message msg(C::PLAYED_CARD, NO_STRING, NO_STRING, PlayedCard);
    GameServer->SendToAllClients(msg.bytes());
}

// server function
void game::deal()
{
    quint8 INITIAL_CARD_QTY = 7;
    //    int NumClients = GameServer->ClientCount();
    quint8 NumPlayers = PlayerList.length();    // number of players
    quint8 NumClients = NumPlayers - 1;         // number of players minus server

    // prepare the proper number of cards for everyone
    for(int CardCount = 0; CardCount < INITIAL_CARD_QTY; ++CardCount)
    {
        // for each client
        for(int i = 0; i < NumPlayers; ++i)
        {
            // give one player the top card from the deck, server gets last card each rotation
            PlayerList[(i+1) % NumClients].Hand.AddCard(MainDeck->TakeTopCard());
        }
//        Hand->AddCard(MainDeck->TakeTopCard());
    }

    // send out each client's hand to them
    for(int i = 1; i < NumPlayers; ++i)
    {
        //            qDebug() << "sending card " << MainDeck->TopCard().CompressedString() << " to client" << ClientNumber;
        message msg(C::CARD_FOR_HAND, NO_STRING, NO_STRING, PlayerList[i].Hand);
        GameServer->SendToClient(msg.bytes(), i-1);
    }




}

