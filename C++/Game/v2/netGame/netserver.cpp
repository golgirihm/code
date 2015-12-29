#include "netserver.h"
#include <QByteArray>

// TODO: remove this include
#include "message.h"
#include <QDebug>

netserver::netserver()
{
    // find ip address of this machine by default
    foreach(QHostAddress adr_it, QNetworkInterface::allAddresses())
        if(adr_it.toIPv4Address()) {ipv4 = adr_it.toString(); break;}

    // default port
    port = 25000;

}
netserver::~netserver()
{
//    qDebug() << "~netserver()";
    emit AboutToClose();
}


void netserver::StartServer()
{
    // start listening for clients
    if(!listen(ipv4, port))
    {
        qDebug() << "ERROR: SERVER COULD NOT START.";
    }
    else
    {
        // whenever there is a new connection from now on, accept it
        connect(this, SIGNAL(newConnection()), this, SLOT(AddTcpClient()));
    }
}

void netserver::AddTcpClient()
{
    QTcpSocket* NewClient = nextPendingConnection();
    ClientList.append(NewClient);
    connect(NewClient, &QTcpSocket::readyRead, this, &netserver::ReadSocketData);
}

void netserver::RemoveTcpClient()
{
    qDebug() << " removing a client";
    QTcpSocket* finishedclient = qobject_cast<QTcpSocket*>(sender());
    disconnect(finishedclient);
    ClientList.removeOne(finishedclient);
}

void netserver::CloseOffServer()
{
    if(isListening())
       close();
}

void netserver::SendToClient(QByteArray private_msg, int client_number)
{
    QTcpSocket* client = ClientList[client_number];
    if(client->state() != QTcpSocket::ConnectedState)
        return;

    private_msg.prepend(MSGTOCLIENT);
    client->write(private_msg, private_msg.size());

    if(!client->flush())
        qDebug() << "ERROR: unsuccessful write in SendToClient";
}

void netserver::ReadSocketData()
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

    // buffer = MsgType + data
    socket->read(buffer.data(), bytes_available);

    unsigned char MsgType = buffer[0];

    // buffer = data
    buffer.remove(0, 1);

    switch(MsgType)
    {
    case MSGTOSERVER:
    {
        // TODO: remove qDebugs
        qDebug() << "--------------Server Read Socket Data-------------";
        qDebug() << buffer.size() << "bytes:";
        message msg(buffer);
        qDebug() << msg.compressedString();

        ExternalData.append(buffer);
        emit ExternalDataReady();

        qDebug() << "**************************************************";
        break;
    }
    case MSGTOCLIENT:
        qDebug() << "error: netserver received a message intended for a client";
        break;
    }
}
void netserver::SendToAllClients(QByteArray public_msg)
{
    // send to each client individually
    for(int i = 0; i < ClientCount(); ++i)
        SendToClient(public_msg, i);
}

void netserver::SendToAll(QByteArray public_msg)
{
    // send to self
    ExternalData.append(public_msg);
    emit ExternalDataReady();

    // send to all others
    SendToAllClients(public_msg);
}


QByteArray netserver::ReceiveExternalData()
{
    if(ExternalData.length() > 1)
        qDebug() << "Warning: ExternalData buffer may be getting clogged";

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

int netserver::ClientCount()
{
    return ClientList.length();
}

