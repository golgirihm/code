#include "lobby.h"
#include "ui_lobby.h"

lobby::lobby(QWidget *parent, const bool& type) :
    QDialog(parent),
    ui(new Ui::lobby)
{
    ui->setupUi(this);

    playertype = type;

    if(playertype == SERVER)
    {
        ui->le_host_ip->hide();
        ui->le_host_port->hide();
        ui->l_host_ip->hide();
        ui->l_host_port_number->hide();
        ui->tb_clientinfo->hide();

        connect(ui->pb_accept, SIGNAL(clicked()), this, SIGNAL(ServerAcceptClicked()));
        connect(ui->pb_start, SIGNAL(clicked()), this, SIGNAL(StartGameClicked()));
    }
    else if(playertype == CLIENT)
    {
        ui->l_your_ip->hide();
        ui->l_your_ip_val->hide();
        ui->l_port->hide();
        ui->l_port_number->hide();
        ui->tb_hostinfo->hide();
        ui->pb_start->hide();

        connect(ui->pb_accept, SIGNAL(clicked()), this, SIGNAL(ClientAcceptClicked()));
    }

    connect(ui->le_host_ip, SIGNAL(textChanged(QString)), this, SIGNAL(TextChanged()));
    connect(ui->le_host_port, SIGNAL(textChanged(QString)), this, SIGNAL(TextChanged()));
    connect(ui->le_username, SIGNAL(textChanged(QString)), this, SIGNAL(TextChanged()));
}

lobby::~lobby()
{
    delete ui;
}

QHostAddress lobby::get_le_host_ip()
{
    return QHostAddress(ui->le_host_ip->text());
}

int lobby::get_le_host_port()
{
    return ui->le_host_port->text().toInt();
}

QString lobby::get_username()
{
    return ui->le_username->text();
}

QString lobby::get_users_joined_text()
{
    return ui->tb_users_joined->toPlainText();
}

void lobby::set_l_your_ip_val(QString adr)
{
    ui->l_your_ip_val->setText(adr);
}

void lobby::set_l_port_number(int port)
{
    ui->l_port_number->setText(QString::number(port));
}

void lobby::set_le_host_ip(QString adr)
{
    ui->le_host_ip->setText(adr);
}

void lobby::setAcceptButton(bool clickable)
{
    ui->pb_accept->setEnabled(clickable);
}

void lobby::setStartButton(bool clickable)
{
    ui->pb_start->setEnabled(clickable);
}

void lobby::set_le_host_ip_enabled(bool clickable)
{
    ui->le_host_ip->setEnabled(clickable);
}

void lobby::set_le_host_port_enabled(bool clickable)
{
    ui->le_host_port->setEnabled(clickable);
}

void lobby::set_users_joined_text(QString all_text)
{
    ui->tb_users_joined->setText(all_text);
}

void lobby::append_users_joined_text(QString appendage)
{
    ui->tb_users_joined->append(appendage);
}
