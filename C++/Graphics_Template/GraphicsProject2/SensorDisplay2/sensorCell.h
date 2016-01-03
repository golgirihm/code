#ifndef SENSORCELL_H
#define SENSORCELL_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class sensorCell : public QGraphicsRectItem
{

public:
    static const quint16 DEF_CELLSIZE = 30;

    sensorCell(quint8 size = cell::DEF_CELLSIZE);
    ~sensorCell();

    void setColor(quint8 r, quint8 g, quint8 b);
    void setString(QString dispString);

};

#endif // SENSORCELL_H
