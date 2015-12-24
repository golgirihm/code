#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QAbstractButton>

#include "server.h"
#include "client.h"
#include "message.h"

#include "lobby.h"
#include "mainscreen.h"

#define USERNAME_S  'U'
#define CLOSELOBBY_S  'Z'
#define CHATMESSAGE_S  'C'

#define LOBBYTEXT_C 'L'
#define CLOSELOBBY_C 'Z'
#define CHATMESSAGE_C 'C'

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();

private:
    Ui::game *ui;
    server* GameServer;
    client* GameClient;
    lobby* GameLobby;
    mainscreen* GameWnd;

    QString UserName;
    bool PlayerType;

public slots:
    void SendToChatroom();

private slots:
    void process_button_click(QAbstractButton *ClickedButton);
    void client_connected();
    void client_ready();
    void server_ready();
    void start_game();
    void lobby_pb_handler();
    void server_process_external_data();
    void client_process_external_data();

signals:

};

#endif // GAME_H
