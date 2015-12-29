#ifndef netserver_H
#define netserver_H

#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
class QByteArray;

class netserver : public QTcpServer
{
    Q_OBJECT

public:
    netserver();
    ~netserver();

    static const quint8 MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    void StartServer();
    void CloseOffServer();

    void SendToClient(QByteArray private_msg, int client_number);
    void SendToAllClients(QByteArray public_msg);
    void SendToAll(QByteArray public_msg);

    // returns the data that was sent to the server from a client
    QByteArray ReceiveExternalData();

    int ClientCount();

private:
    QHostAddress ipv4;
    qint16 port;

    QList<QTcpSocket*> ClientList;  // list of all connected sockets on server
    QList<QByteArray> ExternalData; // queue of received data

private slots:
    void AddTcpClient();
    void RemoveTcpClient();
    void ReadSocketData();

signals:
    void ExternalDataReady();
    void AboutToClose();
};

#endif // netserver_H
