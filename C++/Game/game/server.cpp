#include "server.h"

#include <QtWidgets>
#include <QTextBrowser>
#include <QtNetwork>
#include <QDebug>

server::server(QWidget *parent): QWidget(parent)
{
    qDebug() << "server constructor";

    // find local host ipv4 address by default
    foreach(QHostAddress adr_it, QHostInfo(QHostInfo::fromName(QHostInfo().localHostName())).addresses())
        if(adr_it.toIPv4Address()) {ipv4 = adr_it.toString(); break;}

    // default port
    port = 25000;

    TcpServer = new QTcpServer(this);
}
server::~server()
{
    qDebug() << "server destructor";
}

QHostAddress server::getServerIP()
{
    return ipv4;
}

int server::getServerPort()
{
    return (int) port;
}

void server::setServerInfo(const QHostAddress& server_IP, const quint16& server_port)
{
    ipv4 = server_IP;
    port = server_port;
}

void server::StartServer()
{
    // start listening for clients
    TcpServer->listen(ipv4, port);
    connect(TcpServer, SIGNAL(newConnection()), this, SLOT(AddTcpClient()));
}

void server::AddTcpClient()
{
    ClientList.append(TcpServer->nextPendingConnection());
    connect(ClientList.last(), SIGNAL(readyRead()), this, SLOT(ProcessClientMessage()));
}

void server::RemoveTcpClient()
{
    QTcpSocket* finishedclient = qobject_cast<QTcpSocket*>(sender());
    disconnect(finishedclient, SIGNAL(readyRead()), this, SIGNAL(newData()));
    ClientList.removeOne(finishedclient);
}

void server::CloseOffServer()
{
    if(TcpServer->isListening())
        TcpServer->close();
}

QByteArray server::ReceiveFromClient()
{
    // socket = client that sent the data
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    int bytes_available = socket->bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Server could not read message: not enough bytes available.";
        return QByteArray();
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data

    // buffer = MSGTYPE + data
    socket->read(buffer.data(), bytes_available);

    return buffer;
}

void server::ProcessClientMessage()
{
    QByteArray packet = ReceiveFromClient();

    unsigned char MsgType = packet[0];
    packet.remove(0, 1);

    switch(MsgType)
    {
    case 'S':
        ExternalData.clear();
        ExternalData = packet;
        emit ExternalDataReady();
        break;
    case 'R':
    {
        unsigned char request = packet[0];
        packet.remove(0, 1);
        qDebug() << "server received request of type: " << request;
        emit ClientNeedsData(request);
        break;
    }
    case 'A':
        SendToAll(packet);
        qDebug() << "server relaying a message from one client to all clients";
        break;
    case 'C':
        qDebug() << "error: server received a message intended for a client";
        break;
    }
}

void server::SendToAllClients(QByteArray public_msg)
{
    public_msg.prepend(MSGTOCLIENT);

    foreach(QTcpSocket* client, ClientList)
        client->write(public_msg, public_msg.size());
}

void server::SendToAll(QByteArray public_msg)
{
    ExternalData = public_msg;
    emit ExternalDataReady();

    SendToAllClients(public_msg);
}

QByteArray server::ReceiveExternalData()
{
    QByteArray tempData = ExternalData;
    ExternalData.clear();
    return tempData;
}

