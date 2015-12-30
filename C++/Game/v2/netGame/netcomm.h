#ifndef NETCOMM_H
#define NETCOMM_H

#include <QtNetwork>
#include <QObject>

#define DEFAULTPORT 12345

class netComm : public QObject
{
    Q_OBJECT

public:
    netComm();
    ~netComm();

    enum COMMTYPE : quint8 {NONE, SERVER, CLIENT};

    static const quint8 MSGTOCLIENT = 'C', MSGTOSERVER = 'S';
    static QHostAddress getLocalMachineIPv4();

    quint16 getPort();
    QHostAddress getIPv4();
    void setPort(quint16 newPort);
    void setIPv4(QHostAddress newIPv4);

public slots:
    QByteArray receiveExternalData();

protected:
    COMMTYPE commType;
    QHostAddress ipv4;
    quint16 port;
    QList<QByteArray> externalData; // queue of received data

protected slots:
    void readSocketData();
    void connectionMessage(QTcpSocket *socket = 0);

signals:
    void externalDataReady();
    void aboutToClose();
};

#endif // NETCOMM_H
