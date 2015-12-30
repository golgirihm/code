#include "netserver.h"


#include <QDebug>

netserver::netserver()
{
    commType = COMMTYPE::SERVER;
    tcpServer = new QTcpServer;
}
netserver::~netserver()
{
//    qDebug() << "~netserver()";
    emit aboutToClose();
}

void netserver::StartServer()
{
    // start listening for clients
    if(!tcpServer->listen(ipv4, port))
    {
        qDebug() << "ERROR: SERVER COULD NOT START.";
    }
    else
    {
        // whenever there is a new connection from now on, accept it
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(AddTcpClient()));
    }
}

bool netserver::isListening()
{
    return tcpServer->isListening();
}

void netserver::AddTcpClient()
{
    QTcpSocket* NewClient = tcpServer->nextPendingConnection();
    ClientList.append(NewClient);
    connect(NewClient, SIGNAL(readyRead()), this, SLOT(readSocketData()));
    connectionMessage(NewClient);
    emit clientAdded();
}

void netserver::RemoveTcpClient()
{
    qDebug() << "removing a client...";
    QTcpSocket* finishedclient = qobject_cast<QTcpSocket*>(sender());
    tcpServer->disconnect(finishedclient);
    ClientList.removeOne(finishedclient);
}

void netserver::CloseOffServer()
{
    if(tcpServer->isListening())
       tcpServer->close();
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

void netserver::SendToAllClients(QByteArray public_msg)
{
    // send to each client individually
    for(int i = 0; i < ClientCount(); ++i)
        SendToClient(public_msg, i);
}

void netserver::SendToAll(QByteArray public_msg)
{
    // send to self
    externalData.append(public_msg);
    emit externalDataReady();

    // send to all others
    SendToAllClients(public_msg);
}

int netserver::ClientCount()
{
    return ClientList.length();
}

