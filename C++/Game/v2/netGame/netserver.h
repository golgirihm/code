#ifndef netserver_H
#define netserver_H

#include "netcomm.h"
class QTcpServer;

class netserver : public netComm
{
    Q_OBJECT

public:
    netserver();
    ~netserver();

public slots:
    void StartServer();
    bool isListening();
    void CloseOffServer();
    int ClientCount();

    void SendToClient(QByteArray private_msg, int client_number);
    void SendToAllClients(QByteArray public_msg);
    void SendToAll(QByteArray public_msg);

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> ClientList;  // list of all connected sockets on server

private slots:
    void AddTcpClient();
    void RemoveTcpClient();

signals:
    void clientAdded();

};

#endif // netserver_H
