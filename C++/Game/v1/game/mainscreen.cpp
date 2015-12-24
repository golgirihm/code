#include "mainscreen.h"
#include "ui_mainscreen.h"

mainscreen::mainscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainscreen)
{
    ui->setupUi(this);

    connect(ui->pb_send, SIGNAL(clicked()), this, SIGNAL(ChatMessageReady()));
}

mainscreen::~mainscreen()
{
    delete ui;
}

void mainscreen::AppendToChatRoom(QString msg)
{
    ui->tb_chat_output->append(msg);
}

QString mainscreen::GetChatInput()
{
    return ui->le_chat_input->text();
}

void mainscreen::ClearChatInput()
{
    ui->le_chat_input->clear();
}

