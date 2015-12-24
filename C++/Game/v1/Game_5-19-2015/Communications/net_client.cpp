#include "net_client.h"

// TODO: remove this include
#include "message.h"

net_client::net_client(QWidget *parent): QWidget(parent)
{
    // find local host ipv4 address by default
    foreach(QHostAddress adr_it, QHostInfo(QHostInfo::fromName(QHostInfo().localHostName())).addresses())
        if(adr_it.toIPv4Address()) {serverIP = adr_it.toString(); break;}

    // default port
    port = 25000;

    // set up
    TcpSocket = new QTcpSocket(this);
    connect(TcpSocket, &QTcpSocket::readyRead, this, &net_client::ReadSocketData);
    connect(TcpSocket, &QTcpSocket::readyRead, this, []{qDebug() << "*******************************************";});

    connect(TcpSocket, SIGNAL(connected()), this, SIGNAL(ConnectionMade()));
 //    connect(TcpSocket, SIGNAL(aboutToClose()), this, SIGNAL(AboutToClose()));
//    connect(TcpSocket, SIGNAL(aboutToClose()), this, SLOT(SocketDestroyed()));
//    connect(TcpSocket, SIGNAL(destroyed()), this, SLOT(SocketDestroyed()));

    //  this timer causes the socket to repeatedly attempt to connect to the server
    attempt_timer = new QTimer(this);
    connect(attempt_timer, SIGNAL(timeout()), this, SLOT(attemptToConnect()));
    connect(this, SIGNAL(ConnectionMade()), attempt_timer, SLOT(stop()));
}

net_client::~net_client()
{
//    qDebug() << "~net_client()";
}

QHostAddress net_client::getHostIP()
{
    return serverIP;
}

quint16 net_client::getHostPort()
{
    return port;
}

void net_client::setHostInfo(const QHostAddress& host_IP, const quint16& host_port)
{
    serverIP = host_IP;
    port = host_port;
}

// attempts to connect to the server
void net_client::attemptToConnect()
{
    if(attempt_timer->isActive() && !this->isConnected())
        qDebug() << "Attempt to connect timed out, trying again";

    if(!attempt_timer->isActive())
        attempt_timer->start(3000); // attempt to connect every so often

    TcpSocket->connectToHost(serverIP, port);
}

bool net_client::isConnected()
{
    return (TcpSocket->state() == QTcpSocket::ConnectedState);
}

void net_client::SendToSocket(QByteArray data)
{
    if(!this->isConnected())
        return;

    TcpSocket->write(data, MAX_DATA_SIZE);

    if(!TcpSocket->waitForBytesWritten(WRITE_WAIT_TIME))
//    if(!TcpSocket->flush())
        qDebug() << "ERROR: unsuccessful write in SendToSocket";
}

void net_client::Request(char request)
{
    QByteArray buffer(1, request);
    buffer.prepend(REQUEST);
    SendToSocket(buffer);
}

void net_client::SendToAll(QByteArray message)
{
    message.prepend(MSGTOALL);
    SendToSocket(message);
}

void net_client::SendToServer(QByteArray message)
{
    message.prepend(MSGTOSERVER);
    SendToSocket(message);
}

void net_client::ReadSocketData()
{
    int bytes_available = TcpSocket->bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Message receipt failed: no bytes available.";
        return;
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data
    TcpSocket->read(buffer.data(), bytes_available);

    if(buffer.at(0) == MSGTOCLIENT)
    {
        buffer.remove(0, 1);
    }
    else if(buffer.at(0) == MSGTOSERVER)
    {
        qDebug() << "error: client received a message intended for a server";
        return;
    }
    else if(buffer.at(0) == MSGTOALL)
    {
        qDebug() << "error: client received a message intended for all";
        return;
    }

    qDebug() << "--------------Read Socket Data-------------";
    message temp(buffer);

    ExternalData.append(buffer);
    emit ExternalDataReady();
}

QByteArray net_client::ReceiveExternalData()
{
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
