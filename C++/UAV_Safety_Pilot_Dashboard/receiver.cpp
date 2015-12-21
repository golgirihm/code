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
#include "receiver.h"
#include "ui_receiver.h"
#include <QDebug>

receiver::receiver(QWidget *parent): QMainWindow(parent),
   ui(new Ui::receiver)
{
    ui->setupUi(this);

    // CHOOSE PROTOCOL HERE
//  this->protocol = UDP;
    this->protocol = TCP;

    // save protocol as a string for display purposes
    switch(protocol){
    case TCP:
        string_protocol = "TCP";
        break;
    case UDP:
        string_protocol = "UDP";
        break;
    }

    // change ip address here
    string_ReceiveFromIP = "192.168.0.8";
    port = 12345;
    ReceiveFromIP = QHostAddress(string_ReceiveFromIP);

    // display communication info on dashboard
    ui->label_protocol->setText(string_protocol);
    ui->label_server_ip->setText(string_ReceiveFromIP);
    ui->label_port_number->setText(QString::number(port));
    //ui->label_status->setText("not communicating");
    comm_flag = false;

    // set up differently depending on protocol
    switch(this->protocol){
    case TCP:
    {
        //blockSize = 0;
        TcpSocket = new QTcpSocket(this);
        TcpSocket->connectToHost(ReceiveFromIP, port);
        connect(TcpSocket, SIGNAL(readyRead()), this, SLOT(processPendingData()));
        break;
    }
    case UDP:
    {
        udpSocket = new QUdpSocket(this);
        udpSocket->bind(ReceiveFromIP, port);
        connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingData()));
        break;
    }
    default:
        qDebug() << "Protocol error" << endl;
        break;
    }

    // update the Safety Pilot Dashboard display whenever new data has been received
    connect(this, SIGNAL(newData()), this, SLOT(update_GUI()));

    // this timer checks the communication status
    status_timer = new QTimer(this);
    connect(status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    status_timer->start(500); // update status every 500 milliseconds
}

receiver::~receiver()
{
    delete ui;
}

void receiver::processPendingData()
{
    // communication status
    comm_flag = true;

    // receive data and place it into QByteArray buffer
    switch(this->protocol){
    case TCP:
    {
       QDataStream in(this->TcpSocket);
       in.setVersion(QDataStream::Qt_5_3);

       if(TcpSocket->bytesAvailable() < sizeof(flight_data_t)){
          qDebug() << "Message send failed: not enough bytes available. Trying again.";
          processPendingData();
       }

       buffer.resize(TcpSocket->bytesAvailable());  // resize buffer to fit incoming data
       TcpSocket->read(buffer.data(), TcpSocket->bytesAvailable());
       //blockSize = 0; // reset blockSize for handling the next package
       break;
    }
    case UDP:
        while (udpSocket->hasPendingDatagrams())
        {
            buffer.resize(udpSocket->pendingDatagramSize());                            // resize buffer to fit incoming data
            udpSocket->readDatagram(buffer.data(), udpSocket->pendingDatagramSize());   // get data sent from GCS or other source, store into buffer
        }
        break;
    }

    // transfer data from buffer into local flight_data struct
    memcpy(&this->flight_data, buffer.data(), sizeof(flight_data_t));
    buffer.clear();

    emit newData();

    return;
}

// writes all info to GUI
void receiver::update_GUI(void)
{
    ui->baro_airspeed->display(this->flight_data.baro_airspeed);
    ui->baro_altitude->display(this->flight_data.baro_altitude);
    ui->position_altitude->display(this->flight_data.position_altitude);
    ui->position_heading->display(this->flight_data.position_heading);
    ui->position_latitude->display(this->flight_data.position_latitude);
    ui->position_longitude->display(this->flight_data.position_longitude);
    ui->position_pitch->display(this->flight_data.position_pitch);
    ui->position_roll->display(this->flight_data.position_roll);
    ui->position_yaw->display(this->flight_data.position_yaw);
}

// updates communication status
void receiver::update_status(void){

    if(comm_flag)
        ui->label_status->setText("communicating");
    else
        ui->label_status->setText("not communicating");

    // if this function is called again before processPendingData() is called, dashboard is not communicating
    comm_flag = false;
}
