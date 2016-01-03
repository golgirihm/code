#include "sensor.h"

sensor::sensor(quint16 newNumRows, quint16 newNumCols, quint16 newCellSize, quint16 newGridSpacing)
{
    // assign temporaries to private members
    numRows = newNumRows;
    numCols = newNumCols;
    cellSize = newCellSize;
    gridSpacing = newGridSpacing;

    // calculate dimensions
    cellSpacing = cellSize + gridSpacing;
    quint16 totalHPix = numRows * cellSpacing + gridSpacing;
    quint16 totalVPix = numCols * cellSpacing + gridSpacing;

    // create a graphics scene and set its parameters
    sensorScene = new QGraphicsScene;
    sensorScene->setSceneRect(0,0,totalHPix,totalVPix);
    setFixedSize(totalHPix,totalVPix);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create a matrix of cells
    for(quint16 row = 0, rowPx = gridSpacing; row < numRows; ++row, rowPx +=cellSpacing)
    {
        for(quint16 col = 0, colPx = gridSpacing; col < numCols; ++col, colPx +=cellSpacing)
        {
            cell *newCell = new cell;
            newCell->setPos(rowPx, colPx);
            sensorScene->addItem(newCell);
            cellList.append(newCell);
        }
    }


    // use sensorScene as the scene to visualize in this graphics view
    setScene(sensorScene);
}

sensor::~sensor()
{

}

