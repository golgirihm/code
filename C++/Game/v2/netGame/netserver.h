#ifndef netserver_H
#define netserver_H

#include <QThreadPool>

#include "netcomm.h"
class QTcpServer;

class netserver : public netComm
{
    Q_OBJECT

public:
    netserver();
    ~netserver();

    class client_t
    {
    public:
        QTcpSocket *socket;
        QThread *thread;

//        bool operator==(const client_t *other)
//        {
//            return ((socket == other->socket) && (thread = other->thread));
//        }
    };

public slots:
    bool StartServer() const;
    bool isListening() const;
    void CloseOffServer() const;
    int ClientCount() const;

    void SendToClient(QByteArray private_msg, int client_number);
    void SendToAllClients(QByteArray public_msg);
    void SendToSelf(QByteArray internal_msg);
    void SendToAll(QByteArray public_msg);

private:
    QTcpServer *tcpServer;

//    QList<QThread*> threadList;
    QList<threadedTcpSocket*> clientList;  /// list of all connected sockets on server
//    QList<client_t> clientList;

private slots:
    void AddTcpClient();
    void RemoveTcpClient();

signals:
    void clientAdded(quint8);

};

#endif // netserver_H
