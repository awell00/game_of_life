//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractGrid.hpp"

#include <iostream>
#include <sstream>

#include "CellFactory.hpp"

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

    int AbstractGrid::getHeight() const
    {
        return this->gridHeight;
    }

    int AbstractGrid::getWidth() const
    {
        return this->gridWidth;
    }


    void AbstractGrid::toggleCells() const
    {
        for (int i = 0; this->toModifiateCells.size(); i++)
        {
            toModifiateCells[i]->changeLifeState();
        }
    }

    Cell::AbstractCell* AbstractGrid::getCellByPosition(int lineIndex, int columnIndex) const
    {
        if (lineIndex >= 0 && lineIndex < gridHeight && columnIndex >= 0 && columnIndex < gridWidth) {
            return this->grid[lineIndex][columnIndex];
        } else {
            std::cerr << "Error: Position (" << lineIndex << ", " << columnIndex << ") is out of bounds." << std::endl;
            return nullptr;
        }
    }

    void AbstractGrid::generateNewCells(Utils::File* file) const
    {
        std::string line;
        for (int i = 2; i < gridHeight + 2; i++)
        {
            line = file->readByLine(i);
            std::istringstream iss(line);
            bool alive;
            for (int j = 0; j < gridWidth; j++)
            {
                iss >> alive;
                int position[2] = {i-2, j};
                grid[i-2][j] = Cell::CellFactory::createCell(Cell::CLASSIC, alive, position);
            }
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

