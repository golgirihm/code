#include "game.h"
#include "ui_game.h"

#include "lobby.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    GameServer = 0;
    GameClient = 0;
    GameLobby = 0;
    ui->setupUi(this);

    connect(ui->bg_mainmenu, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(process_button_click(QAbstractButton*)));

//    message temp1('C', "this is a message", "someone");
//    qDebug() << "size of temp1 = " << temp1.bytes().size();

//    message temp2('C', "this is another message!!!", "someone else");
//    qDebug() << "size of temp2 = " << temp2.bytes().size();

}

game::~game()
{
    delete ui;
}

void game::process_button_click(QAbstractButton* ClickedButton)
{
    if(ClickedButton == ui->pb_joingame)
    {
        PlayerType = CLIENT;
        GameLobby = new lobby(this, PlayerType);
//        GameLobby->set_le_host_ip("192.168.0.8");
//        GameLobby->set_le_host_ip("128.172.168.154");
        GameLobby->set_l_port_number(25000);
        connect(GameLobby, SIGNAL(TextChanged()), this, SLOT(lobby_pb_handler()));
        connect(GameLobby, SIGNAL(ClientAcceptClicked()), this, SLOT(client_ready()));

        GameLobby->show();
        this->hide();
    }
    else if(ClickedButton == ui->pb_hostgame)
    {
        PlayerType = SERVER;
        GameServer = new server(this);
        GameServer->StartServer();
        connect(GameServer, SIGNAL(ExternalDataReady()), this, SLOT(server_process_external_data()));

        GameLobby = new lobby(this, PlayerType);
        GameLobby->set_l_your_ip_val(GameServer->getServerIP().toString());
        GameLobby->set_l_port_number(GameServer->getServerPort());
        connect(GameLobby, SIGNAL(TextChanged()), this, SLOT(lobby_pb_handler()));
        connect(GameLobby, SIGNAL(ServerAcceptClicked()), this, SLOT(server_ready()));
        connect(GameLobby, SIGNAL(StartGameClicked()), this, SLOT(start_game()));
        GameLobby->show();
        this->hide();
    }
}

void game::client_ready()
{
    QString oldName = UserName;
    UserName = GameLobby->get_username().simplified();
    if(GameClient == 0)
    {
        GameClient = new client(this);
        connect(GameClient, SIGNAL(ConnectedToSocket()), this, SLOT(client_connected()));
        connect(GameClient, SIGNAL(ExternalDataReady()), this, SLOT(client_process_external_data()));
        GameClient->setHostInfo(GameLobby->get_le_host_ip(), GameLobby->get_le_host_port());
        GameClient->attemptToConnect();
        GameLobby->set_le_host_ip_enabled(false);
        GameLobby->set_le_host_port_enabled(false);
    }
    else if(GameClient->isConnected() && UserName != oldName)
    {
        message msg(USERNAME_S, oldName, UserName);
        GameClient->SendToServer(msg.bytes());
    }

    GameLobby->setAcceptButton(false);
}

void game::server_ready()
{
    QString oldName = UserName;
    UserName = GameLobby->get_username().simplified();

    if(UserName != oldName)
    {
    QString LobbyString = UserName + " is the host.";
    GameLobby->append_users_joined_text(LobbyString);

    // send entire lobby text to all clients
    message msg(LOBBYTEXT_C, GameLobby->get_users_joined_text());
    GameServer->SendToAllClients(msg.bytes());
    }

    GameLobby->setAcceptButton(false);
    GameLobby->setStartButton(true);
}

void game::start_game()
{
    GameWnd = new mainscreen(this);
    GameWnd->show();
    GameLobby->hide();

    message msg(CLOSELOBBY_C);
    GameServer->SendToAllClients(msg.bytes());
    connect(GameWnd, SIGNAL(ChatMessageReady()), this, SLOT(SendToChatroom()));
        qDebug() << "game sees QString(CLOSELOBBY_C) as " << QString(CLOSELOBBY_C) << " and CLOSELOBBY_C as" << CLOSELOBBY_C;
}

void game::lobby_pb_handler()
{

    if(GameLobby->get_username().simplified().length() < 2
            || (PlayerType == CLIENT && (!GameLobby->get_le_host_ip().toIPv4Address() || GameLobby->get_le_host_port() > 65535)))
    {
        GameLobby->setAcceptButton(false);
    }
    else
    {
        GameLobby->setAcceptButton(true);
        GameLobby->setStartButton(false);
    }
}

void game::client_connected()
{
    message msg(USERNAME_S, NONE, UserName);
    GameClient->SendToServer(msg.bytes());
}

void game::server_process_external_data()
{
    message msg_r(GameServer->ReceiveExternalData());

    switch(msg_r.msgtype().toLatin1())
    {
    case USERNAME_S:
    {
        QString LobbyString = msg_r.from() + " has joined.";

        // add user to server's lobby
        GameLobby->append_users_joined_text(LobbyString);

        // send entire lobby text to all clients
        message msg(LOBBYTEXT_C, GameLobby->get_users_joined_text());
        GameServer->SendToAllClients(msg.bytes());
    }
        break;
    case CHATMESSAGE_S:
    {
        QString newPlayer = msg_r.from() + "> " + msg_r.text();

        // put chat in server's chatbox
        GameWnd->AppendToChatRoom(newPlayer);

        // forward to all clients
        message msg(CHATMESSAGE_C, newPlayer);
        GameServer->SendToAllClients(msg.bytes());
    }
        break;
    }
}

void game::client_process_external_data()
{
    message msg_r(GameClient->ReceiveExternalData());

    switch(msg_r.msgtype().toLatin1())
    {
    case LOBBYTEXT_C:
        GameLobby->set_users_joined_text(msg_r.text());
        break;
    case CLOSELOBBY_C:
        GameWnd = new mainscreen(this);
        GameWnd->show();
        GameLobby->hide();
        connect(GameWnd, SIGNAL(ChatMessageReady()), this, SLOT(SendToChatroom()));
        break;
    case CHATMESSAGE_C:
        GameWnd->AppendToChatRoom(msg_r.text());
        break;
    }
}

void game::SendToChatroom()
{
    QString ChatMessage = GameWnd->GetChatInput();
    GameWnd->ClearChatInput();
    message msg(CHATMESSAGE_S, ChatMessage, UserName);

    if(!msg.text().isEmpty())
        switch(PlayerType)
        {
        case CLIENT:
            GameClient->SendToServer(msg.bytes());
            break;
        case SERVER:
            GameServer->SendToAll(msg.bytes());
            break;
        }
}
