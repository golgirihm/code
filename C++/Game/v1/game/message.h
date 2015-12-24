#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QDebug>


#define NONE QChar('\0')

class message
{
public:
    message(QChar msgtype, QString text, QString from, QChar request);
    message(QChar msgtype, QString text, QString from);
    message(QChar msgtype, QString text);
    message(QChar msgtype);

    message(QByteArray bytes);
    ~message();

    QByteArray bytes();
    QChar msgtype();
    QChar request();
    QString from();
    QString text();

//    static constexpr unsigned char USERNAME_S = 'U', CLOSELOBBY_S = 'Z', CHATMESSAGE_S = 'C';
//    static constexpr unsigned char LOBBYTEXT_C = 'L', CLOSELOBBY_C = 'Z', CHATMESSAGE_C = 'C';
//    static constexpr unsigned char NONE = '\0';

private:
    QChar _msgtype;
    QChar _request;
    QString _from;
    QString _text;

signals:

public slots:
};

#endif // MESSAGE_H
