#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include <QHostAddress>

namespace Ui {
class lobby;
}

class lobby : public QDialog
{
    Q_OBJECT

public:
    explicit lobby(const bool& type, QWidget *parent = 0);
    ~lobby();

    QHostAddress get_le_host_ip();
    int get_le_host_port();
    QString get_username();
    QString get_users_joined_text();

    void set_users_joined_text(QString all_text);
    void append_users_joined_text(QString appendage);
    void set_l_your_ip_val(QString adr);
    void set_l_port_number(int port);
    void set_le_host_ip(QString adr);

    void setAcceptButton(bool clickable);
    void setStartButton(bool clickable);
    void set_le_host_ip_enabled(bool clickable);
    void set_le_host_port_enabled(bool clickable);

    static const bool SERVER = true;
    static const bool CLIENT = false;

public slots:

private:
    Ui::lobby *ui;
    bool playertype;

private slots:

signals:
    void ServerAcceptClicked();
    void ClientAcceptClicked();
    void TextChanged();
    void StartGameClicked();

};

#endif // LOBBY_H
