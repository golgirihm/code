#include "sensorCell.h"

sensorCell::sensorCell(quint8 size)
{
    setRect(0, 0, size, size);
}

sensorCell::~sensorCell()
{

}

void sensorCell::setColor(quint8 r, quint8 g, quint8 b)
{
    setBrush(QBrush(QColor(r, g, b)));
}

void sensorCell::setString(QString dispString)
{

}

