//
// Created by Robin Derenty on 03/12/2024.
//

#include "Algorithm.hpp"

#include "GridFactory.hpp"

namespace Utils
{
    Algorithm::Algorithm(Grid::AbstractGrid* m_grid, int m_exactNeighborToBorn, int m_minNeighborToDie, int m_maxNeighborToDie, int m_maxIterations)
    {
        this->grid = m_grid;
        this->exactNeighborToBorn = m_exactNeighborToBorn;
        this->minNeighborToDie = m_minNeighborToDie;
        this->maxNeighborToDie = m_maxNeighborToDie;
        this->maxIterations = m_maxIterations;
    }

    void Algorithm::setNewGrid(Grid::AbstractGrid* newGrid)
    {
        this->grid = newGrid;
    }

    bool Algorithm::generateNewGrid()
    {
        counter++;
        if (counter < maxIterations && !grid->checkSameGrids())
        {
            grid->generateNewCells(exactNeighborToBorn, minNeighborToDie, maxNeighborToDie);
            grid->toggleCells();
            return true;
        }
        return false;
    }



}
