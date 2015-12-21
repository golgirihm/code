/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef RECEIVER_H
#define RECEIVER_H

#include <QtNetwork>
#include <QWidget>
#include <QMainWindow>
#include <QUdpSocket>




namespace Ui {
class receiver;
}

// info from property tree
struct flight_data_t {
    float baro_airspeed;
    float baro_altitude;
    float position_altitude;
    float position_heading;
    float position_latitude;
    float position_longitude;
    float position_pitch;
    float position_roll;
    float position_yaw;
};

enum protocol_t {TCP, UDP};

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QTcpSocket;
class QAction;
class QTimer;
QT_END_NAMESPACE

class receiver : public QMainWindow
{
    Q_OBJECT

public:
    explicit receiver(QWidget *parent = 0);
    ~receiver();

private slots:
    void processPendingData();
    void update_GUI(void);
    void update_status(void);

signals:
    void newData(void);

private:
    Ui::receiver *ui;

    QHostAddress ReceiveFromIP;
    QString string_ReceiveFromIP;
    quint16 port;

    protocol_t protocol;
    QString string_protocol;

    QUdpSocket *udpSocket;
    QTcpSocket *TcpSocket;
    QTimer *status_timer;
    bool comm_flag;
    quint16 blockSize;

    QByteArray buffer;

    QLabel *statusLabel;
    QPushButton *quitButton;

    struct flight_data_t flight_data;
};

#endif
