#ifndef netclient_H
#define netclient_H

#include "netcomm.h"
#include <QTimer>

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
    threadedTcpSocket *tcpSocket;
    QTimer* attempt_timer;

private slots:

signals:
    void connectionMade();

};


#endif // netclient_H
