#include "net_server.h"
#include <QByteArray>

net_server::net_server(QWidget *parent): QWidget(parent)
{
    // find ip address of this machine by default
    foreach(QHostAddress adr_it, QNetworkInterface::allAddresses())
        if(adr_it.toIPv4Address()) {ipv4 = adr_it.toString(); break;}

    // default port
    port = 25000;

    TcpServer = new QTcpServer(this);
}
net_server::~net_server()
{
//    qDebug() << "~net_server()";
    emit AboutToClose();
}

QHostAddress net_server::getServerIP()
{
    return ipv4;
}

int net_server::getServerPort()
{
    return (int) port;
}

void net_server::setServerInfo(const QHostAddress& server_IP, const quint16& server_port)
{
    ipv4 = server_IP;
    port = server_port;
}

void net_server::StartServer()
{
    // start listening for clients
    if(!TcpServer->listen(ipv4, port))
    {
        qDebug() << "ERROR: SERVER COULD NOT START.";
    }
    else
    {
        // whenever there is a new connection from now on, accept it
        connect(TcpServer, SIGNAL(newConnection()), this, SLOT(AddTcpClient()));
    }
}

void net_server::AddTcpClient()
{
    QTcpSocket* NewClient = TcpServer->nextPendingConnection();
    ClientList.append(NewClient);
    connect(NewClient, &QTcpSocket::readyRead, this, &net_server::ReadSocketData);
    connect(NewClient, &QTcpSocket::readyRead, this, []{qDebug() << "*******************************************";});

}

void net_server::RemoveTcpClient()
{
    qDebug() << " removing a client";
    QTcpSocket* finishedclient = qobject_cast<QTcpSocket*>(sender());
    disconnect(finishedclient);
    ClientList.removeOne(finishedclient);
}

void net_server::CloseOffServer()
{
    if(TcpServer->isListening())
        TcpServer->close();
}

void net_server::SendToClient(QByteArray private_msg, int client_number)
{
    private_msg.prepend(MSGTOCLIENT);
    QTcpSocket* client = ClientList[client_number];

    if(client->state() != QAbstractSocket::ConnectedState)
        return;

    client->write(private_msg, MAX_DATA_SIZE);
    if(!client->waitForBytesWritten(WRITE_WAIT_TIME))
//    if(!client->flush())
        qDebug() << "ERROR: unsuccessful write in SendToClient";
}

void net_server::SendToAllClients(QByteArray public_msg)
{
    // send to each client individually
    for(int i = 0; i < ClientCount(); ++i)
        SendToClient(public_msg, i);
}

void net_server::SendToSelf(QByteArray internal_msg)
{
    // place internal_msg onto external data
    ExternalData.append(internal_msg);
    emit ExternalDataReady();
}

void net_server::SendToAll(QByteArray public_msg)
{
    // send to self
    SendToSelf(public_msg);

    // send to all others
    SendToAllClients(public_msg);
}

void net_server::ReadSocketData()
{
    // socket = client that sent the data
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    int bytes_available = socket->bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Message receipt failed: no bytes available.";
        return;
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data

    // buffer = MSGTYPE + data
    socket->read(buffer.data(), bytes_available);
    qDebug() << "--------------Read Socket Data-------------";

    unsigned char MsgType = buffer[0];
    buffer.remove(0, 1);

    switch(MsgType)
    {
    case MSGTOSERVER:
        ExternalData.append(buffer);
        emit ExternalDataReady();
        break;
    case REQUEST:
    {
        unsigned char request = buffer[0];
        buffer.remove(0, 1);
        qDebug() << "net_server received request of type: " << request;
        emit ClientNeedsData(request);
        break;
    }
    case MSGTOALL:
        SendToAll(buffer);
        qDebug() << "net_server relaying a message from one client to all clients";
        break;
    case MSGTOCLIENT:
        qDebug() << "error: net_server received a message intended for a client";
        break;
    }
}

QByteArray net_server::ReceiveExternalData()
{
    // receive the data that has been in queue the longest
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

int net_server::ClientCount()
{
    return ClientList.length();
}

