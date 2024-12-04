//
// Created by Robin Derenty on 03/12/2024.
//

#include "Algorithm.hpp"

namespace Utils
{
    Algorithm::Algorithm(Grid::AbstractGrid* m_grid, int m_exactNeighborToBorn, int m_minNeighborToDie, int m_maxNeighborToDie)
    {
        this->grid = m_grid;
        this->exactNeighborToBorn = m_exactNeighborToBorn;
        this->minNeighborToDie = m_minNeighborToDie;
        this->maxNeighborToDie = m_maxNeighborToDie;
    }

    void Algorithm::setNewGrid(Grid::AbstractGrid* newGrid)
    {
        delete this->grid;
        this->grid = newGrid;
    }

    Grid::AbstractGrid* Algorithm::generateNewGrid()
    {
        return nullptr;
    }



}