#include "netclient.h"

// TODO: remove this include
#include "message.h"
#include <QDebug>

netclient::netclient()
{
    // find local host ipv4 address by default
    foreach(QHostAddress adr_it, QHostInfo(QHostInfo::fromName(QHostInfo().localHostName())).addresses())
        if(adr_it.toIPv4Address()) {serverIP = adr_it.toString(); break;}

    // default port
    port = 25000;

    // set up
    connect(this, &QTcpSocket::readyRead, this, &netclient::ReadSocketData);
    connect(this, SIGNAL(connected()), this, SIGNAL(ConnectionMade()));

    //  this timer causes the socket to repeatedly attempt to connect to the server
    attempt_timer = new QTimer(this);
    connect(attempt_timer, SIGNAL(timeout()), this, SLOT(attemptToConnect()));
    connect(this, SIGNAL(ConnectionMade()), attempt_timer, SLOT(stop()));
    connect(this, SIGNAL(ConnectionMade()), this, SLOT(connectionMessage()));
}

netclient::~netclient()
{
//    qDebug() << "~netclient()";
}

// returns true if socket is in the connected state
bool netclient::isConnected()
{
    return (state() == QTcpSocket::ConnectedState);
}

// repeatedly attempts to connect to the server
void netclient::attemptToConnect()
{
    if(attempt_timer->isActive() && !isConnected())
        qDebug() << "Attempt to connect timed out, trying again";

    if(!attempt_timer->isActive())
        attempt_timer->start(3000); // attempt to connect every so often

    connectToHost(serverIP, port);
}

void netclient::SendToServer(QByteArray data)
{
    if(!this->isConnected())
        return;

    data.prepend(MSGTOSERVER);
    write(data, data.size());

    if(!flush())
        qDebug() << "ERROR: unsuccessful write in SendToSocket";
}

void netclient::ReadSocketData()
{
    int bytes_available = bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Message receipt failed: no bytes available.";
        return;
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data

    // buffer = MsgType + data
    read(buffer.data(), bytes_available);

    unsigned char MsgType = buffer[0];

    // buffer = data
    buffer.remove(0, 1);

    switch(MsgType)
    {
    case MSGTOCLIENT:   // good
    {
        // TODO: remove qDebugs
        qDebug() << "--------------Client Read Socket Data-------------";
        qDebug() << buffer.length() << "bytes:";
        message msg(buffer);
        qDebug() << msg.compressedString();

        ExternalData.append(buffer);
        emit ExternalDataReady();

        qDebug() << "**************************************************";

        break;
    }
    case MSGTOSERVER:
        qDebug() << "error: client received a message intended for a server";
        return;
        break;
    }

}

QByteArray netclient::ReceiveExternalData()
{
    if(ExternalData.length() > 1)
        qDebug() << "Warning: ExternalData buffer may be getting clogged";

    if(!ExternalData.isEmpty())
    {
        QByteArray tempdata = ExternalData.first();
        ExternalData.removeFirst();
        return tempdata;
    }
    else
    {
        qDebug() << "ERROR: ReceiveExternalData attempted to receive data, but there was no external data available";
        return QByteArray();
    }
}

void netclient::connectionMessage()
{
    qDebug() << "Connection made on IPv4 address:" << serverIP << ", port:" << port;
}
