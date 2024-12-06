//
// Created by Robin Derenty on 03/12/2024.
//

#include "ClassicGrid.hpp"

#include <iostream>

#include "CellFactory.hpp"


namespace Grid
{
    ClassicGrid::ClassicGrid(int m_gridHeight, int m_gridWidth) : AbstractGrid(m_gridHeight, m_gridWidth){}

    void ClassicGrid::generateNewCells(int exactNeighborToBorn, int minNeighborToDie, int maxNeighborToDie)
    {
        toModifiateCells.clear();
        for (int x = 0; x < gridHeight; ++x) {
            for (int y = 0; y < gridWidth; ++y) {
                int aliveNeighbors = 0;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i == 0 && j == 0) continue;
                        int nx = x + i;
                        int ny = y + j;
                        if (nx >= 0 && nx < gridHeight && ny >= 0 && ny < gridWidth) {
                            if (grid[nx][ny]->getAlive()) {
                                aliveNeighbors++;
                            }
                        }
                    }
                }
                if (grid[x][y]->getAlive()) {
                    if (aliveNeighbors < minNeighborToDie || aliveNeighbors > maxNeighborToDie) {
                        toModifiateCells.push_back(grid[x][y]);
                    }
                } else {
                    if (aliveNeighbors == exactNeighborToBorn) {
                        toModifiateCells.push_back(grid[x][y]);
                    }
                }
            }
        }

    }


}

