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

#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "sender.h"

Sender::Sender(QWidget *parent): QWidget(parent)
{
    // initialize data in struct
    flight_data.baro_airspeed = 0;
    flight_data.baro_altitude = 0;
    flight_data.position_altitude = 0;
    flight_data.position_heading = 0;
    flight_data.position_latitude = 0;
    flight_data.position_longitude = 0;
    flight_data.position_pitch = 0;
    flight_data.position_roll = 0;
    flight_data.position_yaw = 0;

    // CHOOSE PROTOCOL HERE
//  protocol = UDP;
    protocol = TCP;

    // save protocol as a string for display purposes
    switch(protocol){
    case TCP:
        string_protocol = "TCP";
        break;
    case UDP:
        string_protocol = "UDP";
        break;
    }

    // gather IP and port number from user
    inputbox = new QInputDialog;
    string_SendToIP = inputbox->getText (this, tr("Sender: Setup"), tr("Please enter the IP address of other device"), QLineEdit::Normal, tr(""), NULL, 0, Qt::ImhNone);
    port = inputbox->getInt(this, tr("Sender: Setup"), tr("Please enter the communication port."), 0, 0, 65535, 1, NULL, 0);

//    string_SendToIP = "192.168.0.8";
//    port = 12345;
    SendToIP = QHostAddress(string_SendToIP);

    statusLabel = new QLabel;
    statusLabel->setWordWrap(true);

    startButton = new QPushButton(tr("&Start"));
    quitButton = new QPushButton(tr("&Quit"));

    // if using TCP, wait for a connection before allowing user to attempt sending
    if(protocol == TCP) startButton->setEnabled(false);

    // set up a simple window for the sender program
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Sender"));

    // set up one protocol for sending
    switch(protocol){
    case TCP:
    {
        TcpServer = new QTcpServer(this);
        TcpSocket = new QTcpSocket(this);
        TcpServer->listen(SendToIP, port);
        connect(TcpServer, SIGNAL(newConnection()), this, SLOT(acceptTcpConnection()));
        statusLabel->setText(tr("The %1 server is set up on\n\nIP address: %2\nPort number: %3\n\n"
                                "Open the receiver program now.\nIf it is already opened, please close and reopen it.").arg(string_protocol).arg(string_SendToIP).arg(port));
        break;
    }
    case UDP:
    {
        // UDP does not have handshaking, no need to "listen" or accept connection
        udpSocket = new QUdpSocket(this);
        statusLabel->setText(tr("Ready to send data via %1.\n\nIP address: %2\n\nPort number: %3").arg(string_protocol).arg(string_SendToIP).arg(port));
        break;
    }
    default:
        qDebug() << "Protocol error" << endl;
        break;
    }

    // this timer sets the send frequency
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Send_struct()));

    // chooses the functions of the buttons on the window
    connect(startButton, SIGNAL(clicked()), this, SLOT(startSending()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

}

void Sender::acceptTcpConnection()
{
  static bool firstrun = 1;

  connect(TcpSocket, SIGNAL(connected()), this, SLOT(startSending()));
  TcpSocket = TcpServer->nextPendingConnection();
  statusLabel->setText(tr("Ready to send data via %1.\n\nIP address: %2\n\nPort number: %3").arg(string_protocol).arg(string_SendToIP).arg(port));

  if(firstrun) startButton->setEnabled(true);
    firstrun = 0;
}

void Sender::startSending()
{
    startButton->setEnabled(false);
    timer->start(500); // 500 milliseconds, 2 Hz
}

void Sender::Send_struct(void)
{
    // status label for sender
    statusLabel->setText(tr("Sending data via %1.\n\nSending to IP address: %2\n\nPort number: %3").arg(string_protocol).arg(string_SendToIP).arg(port));

    // this is the data buffer for both UDP and TCP
    buffer.resize(sizeof(flight_data_t));
    memcpy(buffer.data(), &flight_data, sizeof(flight_data_t));

    // write data
    switch(protocol){
    case TCP:
        TcpSocket->write(buffer, sizeof(flight_data_t));
        break;
    case UDP: 
        udpSocket->writeDatagram(buffer.data(), buffer.size(), SendToIP, port);
        break;
    }

    // alter values each iteration to simulate changing data
    // in reality, this data should come from the UAV
    flight_data.baro_airspeed += 0.19;
    flight_data.baro_altitude += 1.1445;
    flight_data.position_altitude += 0.4651;
    flight_data.position_heading += 0.61811;
    flight_data.position_latitude += 0.9871;
    flight_data.position_longitude += 3.14;
    flight_data.position_pitch += 2;
    flight_data.position_roll += 1.94561;
    flight_data.position_yaw += 0.051;
}
