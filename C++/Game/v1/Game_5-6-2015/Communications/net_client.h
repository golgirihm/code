#ifndef net_client_H
#define net_client_H

#include <QtNetwork>
#include <QWidget>
class QByteArray;

class net_client : public QWidget
{
    Q_OBJECT

public:
    explicit net_client(QWidget *parent = 0);
    ~net_client();

    static const int WRITE_WAIT_TIME = 5000;
    static const int MAX_DATA_SIZE = 32767;
    static const char MSGTOALL = 'A', REQUEST = 'R', MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    QHostAddress getHostIP();
    quint16 getHostPort();
    void setHostInfo(const QHostAddress& host_IP, const quint16& host_port);
    void attemptToConnect();
    bool isConnected();

    void Request(char request);
    void SendToAll(QByteArray message);
    void SendToServer(QByteArray message);

    QByteArray ReceiveExternalData();

private:
    QHostAddress serverIP;
    quint16 port;

    QTcpSocket* TcpSocket;
    QTimer* attempt_timer;
    QTimer* status_timer;

    QList<QByteArray> ExternalData;

private slots:
    void ReadSocketData();
    void SendToSocket(QByteArray data);

signals:
    void ConnectionMade();
    void ExternalDataReady();
    void AboutToClose();
};


#endif // net_client_H
