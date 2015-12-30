#include "netcomm.h"

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

    foreach(QHostAddress adr_it, QHostInfo::fromName(QHostInfo().localHostName()).addresses())
        if(adr_it.toIPv4Address()) {localIPv4 = adr_it;}

    return localIPv4;
}

quint16 netComm::getPort()
{
    return port;
}

QHostAddress netComm::getIPv4()
{
    return ipv4;
}

void netComm::setPort(quint16 newPort)
{
    port = newPort;
}

void netComm::setIPv4(QHostAddress newIPv4)
{
    ipv4 = newIPv4;
}

void netComm::readSocketData()
{
    // the socket that sent the data
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    qint64 bytes_available = socket->bytesAvailable();

    if(!bytes_available)
    {
        qDebug() << "Message receipt failed: no bytes available.";
        return;
    }

    QByteArray buffer;
    buffer.resize(bytes_available);  // resize buffer to fit incoming data

    // buffer = MsgType + data
    socket->read(buffer.data(), bytes_available);

    // MsgType = MSGTOSERVER or MSGTOCLIENT
    quint8 MsgType = buffer[0];

    // buffer = data
    buffer.remove(0, 1);

    // if the message arrived at the correct place
    if((MsgType == MSGTOSERVER && commType == COMMTYPE::SERVER) ||
            (MsgType == MSGTOCLIENT && commType == COMMTYPE::CLIENT))
    {
        // TODO: remove qDebugs
        qDebug() << "--------------Read Socket Data-------------";
        qDebug() << buffer.size() << "bytes:";
        qDebug() << message(buffer).compressedString();

        externalData.append(buffer);
        emit externalDataReady();

        qDebug() << "**************************************************";
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

void netComm::connectionMessage(QTcpSocket *socket)
{
    QString descriptorInfo;

    if(socket)
        descriptorInfo = ", socket descriptor:" + QString::number(socket->socketDescriptor());

    qDebug() << "Connection made on IPv4 address:" << ipv4 << ", port:" << port << descriptorInfo;

}
