#include "netclient.h"
#include <QTcpSocket>

#define ATTEMPT_WAIT_MSECS 200

#include <QDebug>

netclient::netclient()
{
    /// allocate memory and establish this as a client
    commType = COMMTYPE::CLIENT;
    tcpSocket = new threadedTcpSocket;
    attempt_timer = new QTimer(this);

    /// set up tcpSocket
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readSocketData()));
    connect(tcpSocket, SIGNAL(connected()), this, SIGNAL(connectionMade()));

    ///  this timer causes the socket to repeatedly attempt to connect to the server
    connect(attempt_timer, SIGNAL(timeout()), this, SLOT(attemptToConnect()));
    connect(tcpSocket, SIGNAL(connected()), attempt_timer, SLOT(stop()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connectionMessage()));
}

netclient::~netclient()
{
    // qDebug() << "~netclient()";
    delete attempt_timer;
    delete tcpSocket;
}

/// returns true if socket is in the connected state
bool netclient::isConnected()
{
    return (tcpSocket->state() == QTcpSocket::ConnectedState);
}

/// repeatedly attempts to connect to the server
void netclient::attemptToConnect()
{
    // attempt to connect every so often if this attempt fails
    if(!attempt_timer->isActive())
        attempt_timer->start(ATTEMPT_WAIT_MSECS);

    if(!isConnected() && tcpSocket->state() != QTcpSocket::ConnectingState)
    {
        tcpSocket->connectToHost(ipv4, port);
        qDebug() << "Attempting to connect on socket descriptor:" << tcpSocket->socketDescriptor();
    }
}

/// sends a message to the server
void netclient::SendToServer(QByteArray data)
{
    if(!isConnected())
    {
        qDebug() << "CLIENT: Warning - SendToServer failed, client is not connected. returning.";
        return;
    }

    data.prepend(MSGTOSERVER);
    tcpSocket->write(data);

    if(!tcpSocket->flush())
        qDebug() << "ERROR: unsuccessful write in SendToSocket";
}
