#ifndef SENSOR_H
#define SENSOR_H

#include "cell.h"
#include <QGraphicsView>

#define DEF_NUMROWS 4
#define DEF_NUMCOLS 4
#define DEF_CELLSIZE 70
#define DEF_GRIDSPACING 4

class sensor : public QGraphicsView
{
public:

    sensor(quint16 newNumRows = DEF_NUMROWS,
           quint16 newNumCols = DEF_NUMCOLS,
           quint16 newCellSize = DEF_CELLSIZE,
           quint16 newGridSpacing = DEF_GRIDSPACING);
    ~sensor();


private:
    quint16 numRows;
    quint16 numCols;
    quint16 cellSize;
    quint16 gridSpacing;
    quint16 cellSpacing;

    QGraphicsScene *sensorScene;
    QList<cell*> cellList;


};


#endif // SENSOR_H

