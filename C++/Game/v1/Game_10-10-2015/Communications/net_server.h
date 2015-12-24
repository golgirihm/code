#ifndef net_server_H
#define net_server_H

#include <QtNetwork>
#include <QWidget>
class QByteArray;

class net_server : public QObject
{
    Q_OBJECT

public:
    explicit net_server(QObject *parent = 0);
    ~net_server();
    QHostAddress getServerIP();
    int getServerPort();
    void setServerInfo(const QHostAddress& server_IP, const quint16& server_port);

    static const int WRITE_WAIT_TIME = 10000;
    static const int MAX_DATA_SIZE = 32767;
    static const unsigned char MSGTOALL = 'A', REQUEST = 'R', MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    void StartServer();
    void CloseOffServer();

    void SendToClient(QByteArray private_msg, int client_number);
    void SendToAllClients(QByteArray public_msg);
    void SendToSelf(QByteArray internal_msg);
    void SendToAll(QByteArray public_msg);

    // returns the data that was sent to the server from a client
    QByteArray ReceiveExternalData();

    int ClientCount();

private:
    QHostAddress ipv4;
    qint16 port;

    QTcpServer *TcpServer;
    QList<QTcpSocket*> ClientList;

    QList<QByteArray> ExternalData;

private slots:
    void AddTcpClient();
    void RemoveTcpClient();
    void ReadSocketData();

signals:
    void ExternalDataReady();
    void ClientNeedsData(QChar request);
    void AboutToClose();
};

#endif // net_server_H
