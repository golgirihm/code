#ifndef SENSORCELL_H
#define SENSORCELL_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class sensorCell : public QGraphicsRectItem
{

public:
    static const quint16 DEF_CELLSIZE = 50;

    sensorCell(quint8 size = sensorCell::DEF_CELLSIZE);
    ~sensorCell();

    void setColor(quint8 r, quint8 g, quint8 b);
    void setString(QString newSensorCellString);

private:
    QGraphicsRectItem *sensorCellRect;
    QGraphicsTextItem *sensorCellString;

};

#endif // SENSORCELL_H
