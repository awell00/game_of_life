//
// Created by Robin Derenty on 03/12/2024.
//

#include "ClassicGrid.hpp"

#include <iostream>

#include "CellFactory.hpp"


namespace Grid
{
    ClassicGrid::ClassicGrid(int m_gridHeight, int m_gridWidth) : AbstractGrid(m_gridHeight, m_gridWidth){}

    void ClassicGrid::generateNewCells()
    {
        for (int i = 0; i < this->gridHeight; i++)
        {
            for (int j = 0; j < this->gridWidth; j++)
            {
                int position[2] = {i, j};
                grid[i][j] = Cell::CellFactory::createCell(Cell::CLASSIC, true, position);
            }
        }
    }

    void ClassicGrid::generateNewCells(Utils::File* file)
    {
        ;
    }

    void ClassicGrid::checkSameGrids()
    {
       ;
    }

}

