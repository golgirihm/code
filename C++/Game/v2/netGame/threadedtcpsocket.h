#ifndef THREADEDTCPSOCKET_H
#define THREADEDTCPSOCKET_H

#include <QThread>
#include <QTcpSocket>

class threadedTcpSocket : public QThread
{
    Q_OBJECT

public:
    threadedTcpSocket();
    threadedTcpSocket(QTcpSocket *preAllocatedSocket);
    ~threadedTcpSocket();

    void run();

    void connectToHost(const QHostAddress &address, quint16 port);
    void close();
    qint64 read(char * data, qint64 maxSize);
    qint64 write(const QByteArray & byteArray);
    QAbstractSocket::SocketState state() const;
    qintptr socketDescriptor() const;

    /// "deprecated"?
    quint64 bytesAvailable() const;
    bool flush();
    bool waitForBytesWritten(int msecs = 30000);

private:
    QTcpSocket *tcpSocket;

signals:
    void connected();
    void readyRead();
};

#endif // THREADEDTCPSOCKET_H
