#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class cell : public QGraphicsRectItem
{
public:
    cell(quint8 size, QGraphicsView *parentView = 0);
    ~cell();
};

#endif // CELL_H
