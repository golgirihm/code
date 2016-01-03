#include "cell.h"

cell::cell(quint8 size, QGraphicsView *parentView)
{
    setRect(0, 0, size, size);
}

cell::~cell()
{

}

