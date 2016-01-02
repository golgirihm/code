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
    void StartServer() const;
    bool isListening() const;
    void CloseOffServer() const;
    int ClientCount() const;

    void SendToClient(QByteArray private_msg, int client_number);
    void SendToAllClients(QByteArray public_msg);
    void SendToSelf(QByteArray internal_msg);
    void SendToAll(QByteArray public_msg);

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> ClientList;  // list of all connected sockets on server

private slots:
    void AddTcpClient();
    void RemoveTcpClient();

signals:
    void clientAdded(quint8);

};

#endif // netserver_H
