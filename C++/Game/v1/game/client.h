#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QWidget>
#include <QMainWindow>
#include <QUdpSocket>

namespace Ui
{
class client;
}

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QTcpSocket;
class QAction;
class QTimer;
QT_END_NAMESPACE

class client : public QWidget
{
    Q_OBJECT
public:
    explicit client(QWidget *parent = 0);
    ~client();
    const unsigned char MSGTOALL = 'A', REQUEST = 'R', MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    QHostAddress getHostIP();
    quint16 getHostPort();
    void setHostInfo(const QHostAddress& host_IP, const quint16& host_port);
    void attemptToConnect();
    bool isConnected();

    void Request(unsigned char request);
    void SendToAll(QByteArray message);
    void SendToServer(QByteArray message);

    QByteArray ReceiveExternalData();

private:
    QHostAddress serverIP;
    quint16 port;

    QTcpSocket* TcpSocket;
    QTimer* attempt_timer;
    QTimer* status_timer;

private slots:

signals:
    void ConnectedToSocket();
    void ExternalDataReady();
};


#endif // CLIENT_H
