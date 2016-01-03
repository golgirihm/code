#include "sensorCell.h"

sensorCell::sensorCell(quint8 size)
{
    /// allocate all graphics items
    sensorCellRect = new QGraphicsRectItem;
    sensorCellString = new QGraphicsTextItem;

    /// initial positioning of graphics items
    sensorCellRect->setRect(0, 0, size, size);

    /// set all graphics items to have a parent of this QGraphicsRectItem
    sensorCellRect->setParentItem((QGraphicsRectItem*)this);
    sensorCellString->setParentItem((QGraphicsRectItem*)this);

    /// initial state of this sensorCell
    setColor(200,200,200);
    setString("NO DATA");
}

sensorCell::~sensorCell()
{

}

void sensorCell::setColor(quint8 r, quint8 g, quint8 b)
{
    sensorCellRect->setBrush(QBrush(QColor(r, g, b)));
}

void sensorCell::setString(QString newSensorCellString)
{
    sensorCellString->setPlainText(newSensorCellString);
}

