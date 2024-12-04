//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include "AbstractGrid.hpp"

namespace Utils
{
    class Algorithm {
    private:
        Grid::AbstractGrid* grid;
        int exactNeighborToBorn;
        int minNeighborToDie;
        int maxNeighborToDie;
    public:
        Algorithm(Grid::AbstractGrid* m_grid, int m_exactNeighborToBorn, int m_minNeighborToDie, int m_maxNeighborToDie);
        void setNewGrid(Grid::AbstractGrid* newGrid);
        Grid::AbstractGrid* generateNewGrid();
    };
}



#endif //ALGORITHM_HPP
