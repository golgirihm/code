#ifndef netclient_H
#define netclient_H

#include <QtNetwork>
#include <QTcpSocket>
#include "netcomm.h"
class QByteArray;

class netclient : public netComm
{
    Q_OBJECT

public:
    netclient();
    ~netclient();

public slots:
    bool isConnected();
    void attemptToConnect();

    // sends data to the connected server
    void SendToServer(QByteArray data);



private:
    QTcpSocket *tcpSocket;
    QTimer* attempt_timer;
    QTimer* status_timer;

private slots:

signals:
    void connectionMade();

};


#endif // netclient_H
