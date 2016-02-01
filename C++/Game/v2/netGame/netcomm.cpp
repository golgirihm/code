#include "netcomm.h"

#include "threadedtcpsocket.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QHostInfo>

// TODO: remove this include
#include "message.h"

netComm::netComm()
{
    commType = COMMTYPE::NONE;

    // find ip address of this machine by default
    ipv4 = getLocalMachineIPv4();
    port = DEFAULTPORT;
}

netComm::~netComm()
{

}

QHostAddress netComm::getLocalMachineIPv4()
{
    QHostAddress localIPv4;

    foreach(QHostAddress itAdr, QHostInfo::fromName(QHostInfo().localHostName()).addresses())
        if(itAdr.toIPv4Address()) {localIPv4 = itAdr;}

    return localIPv4;
}

const quint16 &netComm::getPort() const
{
    return port;
}

const QHostAddress &netComm::getIPv4() const
{
    return ipv4;
}

void netComm::setPort(const quint16 &newPort)
{
    port = newPort;
}

void netComm::setIPv4(const QHostAddress &newIPv4)
{
    ipv4 = newIPv4;
}

void netComm::readSocketData()
{
    // the socket that sent the data
//    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    threadedTcpSocket *socket = qobject_cast<threadedTcpSocket*>(sender());

    qint64 bytesAvailable = socket->bytesAvailable();

    if(!bytesAvailable)
    {
        qDebug() << "Message receipt failed: no bytes available.";
        return;
    }

    QByteArray buffer;
    buffer.resize(bytesAvailable);  // resize buffer to fit incoming data

    // buffer = MsgType + data
    socket->read(buffer.data(), bytesAvailable);

    // MsgType = MSGTOSERVER or MSGTOCLIENT
    quint8 MsgType = buffer[0];

    // buffer = data
    buffer.remove(0, 1);

    // if the message arrived at the correct place
    if((MsgType == MSGTOSERVER && commType == COMMTYPE::SERVER) ||
            (MsgType == MSGTOCLIENT && commType == COMMTYPE::CLIENT))
    {
        // TODO: remove qDebugs
        qDebug()  << "\n--------------Appending Socket Data To externalData--------------";
//        qDebug() << buffer.size() << "bytes:";
//        qDebug() << message(buffer).compressedString();

        externalData.append(buffer);
        emit externalDataReady();

        qDebug() << "*****************************************************************";
    }
    else
    {
        qDebug() << "ERROR: RECEIVED A MESSAGE INTENDTED FOR SOMEONE ELSE.";
    }
}

QByteArray netComm::receiveExternalData()
{
    if(externalData.length() > 1)
        qDebug() << "Warning: ExternalData buffer may be getting clogged";

    // receive the data that has been in queue the longest
    if(!externalData.isEmpty())
    {
        return externalData.takeFirst();
    }
    else
    {
        qDebug() << "ERROR: receiveExternalData attempted to receive data, but there was no external data available";
        return QByteArray();
    }
}

void netComm::connectionMessage(threadedTcpSocket *socket)
{
    QString descriptorInfo;

    if(socket)
        descriptorInfo = ", socket descriptor:" + QString::number(socket->socketDescriptor());

    qDebug() << "Connection made on IPv4 address:" << ipv4 << ", port:" << port << descriptorInfo;

}
