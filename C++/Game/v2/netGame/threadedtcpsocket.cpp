#include "threadedtcpsocket.h"

threadedTcpSocket::threadedTcpSocket()
{
    tcpSocket = new QTcpSocket;

    /// \todo: see if this is correct
    this->start();
}

threadedTcpSocket::threadedTcpSocket(QTcpSocket *preAllocatedSocket)
{
    tcpSocket = preAllocatedSocket;

    /// \todo: see if this is correct
    this->start();
}

threadedTcpSocket::~threadedTcpSocket()
{
    delete tcpSocket;
}

void threadedTcpSocket::run()
{
    connect(tcpSocket, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SIGNAL(readyRead()));

    this->exec();
}

void threadedTcpSocket::connectToHost(const QHostAddress &address, quint16 port)
{
    tcpSocket->connectToHost(address, port);
}

void threadedTcpSocket::close()
{
    tcpSocket->close();
}

qint64 threadedTcpSocket::read(char *data, qint64 maxSize)
{
    return tcpSocket->read(data, maxSize);
}

qint64 threadedTcpSocket::write(const QByteArray &byteArray)
{
    qint64 bytesWritten = tcpSocket->write(byteArray);
    this->msleep(2000);
    return bytesWritten;
}

QAbstractSocket::SocketState threadedTcpSocket::state() const
{
    return tcpSocket->state();
}

qintptr threadedTcpSocket::socketDescriptor() const
{
    return tcpSocket->socketDescriptor();
}

quint64 threadedTcpSocket::bytesAvailable() const
{
    return tcpSocket->bytesAvailable();
}

bool threadedTcpSocket::flush()
{
    return tcpSocket->flush();
}

bool threadedTcpSocket::waitForBytesWritten(int msecs)
{
    return tcpSocket->waitForBytesWritten(msecs);
}

