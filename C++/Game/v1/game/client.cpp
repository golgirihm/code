#include "client.h"

client::client(QWidget *parent): QWidget(parent)
{
     qDebug() << "client constructor";

    // find local host ipv4 address by default
    foreach(QHostAddress adr_it, QHostInfo(QHostInfo::fromName(QHostInfo().localHostName())).addresses())
        if(adr_it.toIPv4Address()) {serverIP = adr_it.toString(); break;}

    // default port
    port = 25000;

    // set up
    TcpSocket = new QTcpSocket(this);
    connect(TcpSocket, SIGNAL(readyRead()), this, SIGNAL(ExternalDataReady()));

    //  this timer causes the socket to repeatedly attempt to connect to the server
    attempt_timer = new QTimer(this);
    connect(attempt_timer, SIGNAL(timeout()), this, SLOT(attemptToConnect()));
}

client::~client()
{
    qDebug() << "client destructor";
}

QHostAddress client::getHostIP()
{
    return serverIP;
}

quint16 client::getHostPort()
{
    return port;
}

void client::setHostInfo(const QHostAddress& host_IP, const quint16& host_port)
{
    serverIP = host_IP;
    port = host_port;
}

// attempts to connect to the server
void client::attemptToConnect()
{
    TcpSocket->connectToHost(serverIP, port);

    if(!attempt_timer->isActive())
        attempt_timer->start(3000); // attempt to connect every 3 seconds

    if(TcpSocket->isValid())
    {
        attempt_timer->stop();
        emit ConnectedToSocket();
    }
    else
        qDebug() << "attempt to connect failed";
}

bool client::isConnected()
{
    return TcpSocket->isValid();
}

void client::Request(unsigned char request)
{
    QByteArray buffer(1, '3');
    buffer.fill(request);
    buffer.prepend(REQUEST);
    TcpSocket->write(buffer, buffer.size());
}

void client::SendToAll(QByteArray message)
{
    message.prepend(MSGTOALL);
    TcpSocket->write(message, message.size());
}

void client::SendToServer(QByteArray message)
{
    message.prepend(MSGTOSERVER);
    TcpSocket->write(message, message.size());
}

QByteArray client::ReceiveExternalData()
{
    int bytes_available = TcpSocket->bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Message receipt failed: not enough bytes available.";
        return QByteArray();
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data
    TcpSocket->read(buffer.data(), bytes_available);

    if(buffer.at(0) == MSGTOCLIENT)
    {
        buffer.remove(0, 1);
//        qDebug() << "removing MSGTOCLIENT flag in buffer in receiveexternaldata function. Rest of data is: " << buffer;
    }
    else
        qDebug() << "error: client received a message intended for a server";

    return buffer;
}
