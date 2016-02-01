#include "netserver.h"
#include <QTcpServer>
#include <QTcpSocket>

#include <QDebug>

netserver::netserver()
{
    commType = COMMTYPE::SERVER;
    tcpServer = new QTcpServer;

    /// start indexing the client list at the number 1
    threadedTcpSocket *PLACEHOLDER_SOCKET = 0;
//    QThread *PLACEHOLDER_THREAD = 0;
//    clientList.append({PLACEHOLDER_SOCKET, PLACEHOLDER_THREAD});
    clientList.append(PLACEHOLDER_SOCKET);
}
netserver::~netserver()
{
//    qDebug() << "~netserver()";
//    emit aboutToClose();
    while (!clientList.isEmpty())
    {
        qDebug() << "Deleting a client from clientList";
        delete clientList.takeFirst();
//        delete clientList.takeFirst().thread;
    }

    delete tcpServer;

}

bool netserver::StartServer() const
{
    /// start listening for clients
    if(tcpServer->listen(ipv4, port))
    {
        /// whenever there is a new connection from now on, accept it
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(AddTcpClient()));
        return true;
    }
    else
    {
        qDebug() << "ERROR: SERVER COULD NOT START.";
        return false;
    }
}

bool netserver::isListening() const
{
    return tcpServer->isListening();
}

void netserver::AddTcpClient()
{
    threadedTcpSocket *newSocket = new threadedTcpSocket(tcpServer->nextPendingConnection());

//    QTcpSocket* newSocket = tcpServer->nextPendingConnection();

    /// \badcode
//    QThread *newThread = new QThread;
//    newSocket->moveToThread(newThread);
//    newThread->start();
//    threadList.append(newThread);
    clientList.append(newSocket);
//    clientList.append({newSocket, newThread});
    /// this is questionable

    connect(newSocket, SIGNAL(readyRead()), this, SLOT(readSocketData()));
    connectionMessage(newSocket);
//    emit clientAdded((quint8)clientList.indexOf({newSocket, newThread}));
//    emit clientAdded((quint8)clientList.indexOf(clientList.last()));
    emit clientAdded((quint8)(ClientCount()-1));
}

void netserver::RemoveTcpClient()
{
    qDebug() << "removing a client...";
//    QTcpSocket* finishedclient = qobject_cast<QTcpSocket*>(sender());
    threadedTcpSocket *finishedclient = qobject_cast<threadedTcpSocket*>(sender());
    finishedclient->close();
//    clientList.removeOne(finishedclient); /// careful, this could cause ID's to become incorrect
}

void netserver::CloseOffServer() const
{
    if(tcpServer->isListening())
       tcpServer->close();
}

void netserver::SendToClient(QByteArray private_msg, int client_number)
{

    threadedTcpSocket *client = clientList[client_number];
//    QTcpSocket* client = clientList[client_number];
//    QThread* thread = clientList[client_number].thread;

//    qDebug() << "thread is " << thread->isRunning();

    if(client == 0)
    {
        qDebug() << "ERROR in netserver::SendToClient -- clientList[" << client_number << "] == 0";
        return;
    }

    if(client->state() != QTcpSocket::ConnectedState)
    {
        qDebug() << "ERROR in netserver::SendToClient -- clientList[" << client_number << "]->state() != QTcpSocket::ConnectedState";
        return;
    }

    private_msg.prepend(MSGTOCLIENT);
    client->write(private_msg);

    if(!client->flush())
        qDebug() << "ERROR: unsuccessful write in SendToClient";

    /// \todo: LEFT OFF HERE
    /// THIS ISN'T WORKING -- it is blocking
    client->waitForBytesWritten();
//    thread->msleep(100);


}

void netserver::SendToAllClients(QByteArray public_msg)
{
    /// send to each client individually
    for(int i = 1; i < ClientCount(); ++i)
        SendToClient(public_msg, i);
}

void netserver::SendToSelf(QByteArray internal_msg)
{
    externalData.append(internal_msg);
    emit externalDataReady();
}

void netserver::SendToAll(QByteArray public_msg)
{
    /// send to self
    SendToSelf(public_msg);

    /// send to all others
    SendToAllClients(public_msg);
}

int netserver::ClientCount() const
{
    return clientList.length();
}

