#ifndef netclient_H
#define netclient_H

#include <QtNetwork>
#include <QTcpSocket>
class QByteArray;

class netclient : public QTcpSocket
{
    Q_OBJECT

public:
    netclient();
    ~netclient();

    static const quint8 MSGTOCLIENT = 'C', MSGTOSERVER = 'S';

public slots:
    bool isConnected();
    void attemptToConnect();

    void SendToServer(QByteArray data);

    // returns the data that was sent to the client from the server
    QByteArray ReceiveExternalData();


    void connectionMessage();

private:
    QHostAddress serverIP;
    quint16 port;

//    QTcpSocket* TcpSocket;
    QTimer* attempt_timer;
    QTimer* status_timer;

    QList<QByteArray> ExternalData; // queue of received data

private slots:
    void ReadSocketData();


signals:
    void ExternalDataReady();
    void ConnectionMade();
};


#endif // netclient_H
