#ifndef GAME_H
#define GAME_H

#include <QMainWindow>


class QAbstractButton;
class QTimer;

class net_server;
class net_client;
class message;
class lobby;
class mainscreen;
class card;
class cardstack;

namespace Ui {
    class game;
}

struct playerinfo
{
    QString UserName;
    int NumCards;
    int Number;
};

namespace S
{   // to-server message types
    enum S_t : unsigned char
    {
        USERNAME = 'U',
        CHATMESSAGE = 'Q',
    };
}

namespace C
{   // to-client message types
    enum C_t : unsigned char
    {
        LOBBYTEXT = 'L',
        OPEN_MAIN_GAME = 'O',
        CHATMESSAGE = 'M',
        CARD_FOR_HAND = 'C',
        PLAYERS_STATUS = 'P',
        DECK_COUNT = 'D',
        PLAYED_CARD = 'T'
    };
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();

    static const bool SERVER = true;
    static const bool CLIENT = false;
    static const int UPDATE_INTERVAL = 10000;

/*********************************************/
/******************* PRIVATE *****************/
private:

    // general
    Ui::game *ui;
    lobby *GameLobby;
    mainscreen *GameWnd;

    QString UserName;
    bool PlayerType;
    cardstack *Hand;

    // server
    net_server *GameServer;
    cardstack *MainDeck;
    cardstack *PlayedCards;
    QList<playerinfo> PlayerList;
    QTimer *UpdateTimer1;
    QTimer *UpdateTimer2;
    QTimer *UpdateTimer3;


    // client
    net_client* GameClient;


/*********************************************/
/**************** PRIVATE SLOTS **************/
private slots:

    // general
    void process_opening_screen_button_click(QAbstractButton *ClickedButton);
    void lobby_pb_handler();
    void SendToChatroom();

    // server
    void server_ready();
    void start_game();
    void server_process_external_data();
    void deal();
    void UpdatePlayersStatus();
    void UpdateDeckCount();
    void UpdatePlayedCard();

    // client
    void client_ready();
    void client_connected();
    void client_process_external_data();


/*********************************************/
/****************** SIGNALS ******************/
signals:

    // server



};

#endif // GAME_H
