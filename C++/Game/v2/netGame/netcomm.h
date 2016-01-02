#ifndef NETCOMM_H
#define NETCOMM_H

#include <QObject>
#include <QHostAddress>
class QHostInfo;
class QTcpSocket;

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

    const quint16 &getPort() const;
    const QHostAddress &getIPv4() const;
    void setPort(const quint16 &newPort);
    void setIPv4(const QHostAddress &newIPv4);

public slots:
    QByteArray receiveExternalData();

protected:
    COMMTYPE commType;
    QHostAddress ipv4;
    quint16 port;
    QList<QByteArray> externalData; // queue of received data

protected slots:
    void connectionMessage(QTcpSocket *socket = 0);

private slots:
    void readSocketData();

signals:
    void externalDataReady();
    void aboutToClose();
};

#endif // NETCOMM_H
