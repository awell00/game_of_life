//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractGrid.hpp"
namespace Grid
{
    AbstractGrid::AbstractGrid(int m_gridHeight, int m_gridWidth) : gridHeight(m_gridHeight), gridWidth(m_gridWidth), aliveCells({nullptr}),toModifiateCells({nullptr})
    {
        grid = new Cell::AbstractCell**[gridHeight];
        for (int i = 0; i < gridHeight; i++)
        {
            grid[i] = new Cell::AbstractCell*[gridWidth];
            for (int j = 0; j < gridWidth; j++)
            {
                grid[i][j] = nullptr;
            }
        }
    }

    void AbstractGrid::toggleCells()
    {
        for (int i = 0; this->toModifiateCells.size(); i++)
        {
            toModifiateCells[i]->changeLifeState();
        }
    }

    AbstractGrid::~AbstractGrid()
    {
        for (int i = 0; i < gridHeight; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
    }
}

