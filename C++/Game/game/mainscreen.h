#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>

namespace Ui {
class mainscreen;
}

class mainscreen : public QDialog
{
    Q_OBJECT

public:
    explicit mainscreen(QWidget *parent = 0);
    ~mainscreen();
    void AppendToChatRoom(QString msg);
    QString GetChatInput();
    void ClearChatInput();

private:
    Ui::mainscreen *ui;

signals:
    void ChatMessageReady();

};

#endif // MAINSCREEN_H
