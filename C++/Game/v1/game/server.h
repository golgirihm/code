#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QWidget>
#include <QHostAddress>
#include <QTextBrowser>
#include <QInputDialog>



QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QPushButton;
class QTimer;
class QTcpSocket;
QT_END_NAMESPACE

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();
    QHostAddress getServerIP();
    int getServerPort();
    void setServerInfo(const QHostAddress& server_IP, const quint16& server_port);

    const unsigned char MSGTOALL = 'A', REQUEST = 'R', MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    void StartServer();
    void CloseOffServer();

    void SendToAllClients(QByteArray public_msg);
    void SendToAll(QByteArray public_msg);

    // returns the data that was sent to the server from a client
    QByteArray ReceiveExternalData();

private:
    QHostAddress ipv4;
    qint16 port;

    QTcpServer *TcpServer;
    QList<QTcpSocket*> ClientList;

    QByteArray ExternalData;

private slots:
    void AddTcpClient();
    void RemoveTcpClient();
    QByteArray ReceiveFromClient();
    void ProcessClientMessage();

signals:
    void ExternalDataReady();
    void ClientNeedsData(QChar request);
};

#endif // SERVER_H
