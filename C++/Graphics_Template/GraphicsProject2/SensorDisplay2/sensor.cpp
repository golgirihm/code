#include "sensor.h"

sensor::sensor(quint16 newNumRows, quint16 newNumCols, quint16 newCellSize, quint16 newGridSpacing)
{
    numRows = newNumRows;
    numCols = newNumCols;
    cellSize = newCellSize;
    gridSpacing = newGridSpacing;
    cellSpacing = cellSize + gridSpacing;

    quint16 totalHPix = numRows * cellSpacing + gridSpacing;
    quint16 totalVPix = numCols * cellSpacing + gridSpacing;

    sensorScene = new QGraphicsScene;
    sensorScene->setSceneRect(0,0,totalHPix,totalVPix);

    // use sensorScene as the scene to visualize
    setScene(sensorScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(totalHPix,totalVPix);

    // create a matrix of cells
    for(quint16 row = 0; row < numRows; ++row)
    {
        for(quint16 col = 0; col < numCols; ++col)
        {
            cell *newCell = new cell(cellSize);
            newCell->setPos(gridSpacing + row*cellSpacing, gridSpacing + col * cellSpacing);
            sensorScene->addItem(newCell);
            cellList.append(newCell);
        }
    }


}

sensor::~sensor()
{

}

