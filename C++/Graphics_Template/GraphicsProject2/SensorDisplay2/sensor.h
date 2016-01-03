#ifndef SENSOR_H
#define SENSOR_H

#include "sensorCell.h"
#include <QGraphicsView>



class sensor : public QGraphicsView
{

    Q_OBJECT

public:
    static const quint16 DEF_NUMROWS = 4;
    static const quint16 DEF_NUMCOLS = 4;
    static const quint16 DEF_GRIDSPACING = 4;

    sensor(quint16 newNumRows = sensor::DEF_NUMROWS,
           quint16 newNumCols = sensor::DEF_NUMCOLS,
           quint16 newCellSize = cell::DEF_CELLSIZE,
           quint16 newGridSpacing = sensor::DEF_GRIDSPACING);
    ~sensor();

public slots:


private:
    quint16 numRows;
    quint16 numCols;
    quint16 cellSize;
    quint16 gridSpacing;
    quint16 cellSpacing;

    QGraphicsScene *sensorScene;
    QList<sensorCell*> cellList;


};


#endif // SENSOR_H

