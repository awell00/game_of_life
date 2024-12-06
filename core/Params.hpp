//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef PARAMS_HPP
#define PARAMS_HPP
#include "AbstractGrid.hpp"


namespace Utils
{
    class Params {
    private:
        int height;
        int width;
        int maxIterations;
        Grid::GridType gridType;
        int exactNeighborToBorn;
        int minNeighborToDie;
        int maxNeighborToDie;
    public:
        Params(int m_height, int m_width, int m_maxIterations, Grid::GridType m_gridType, int m_exactNeighborToBorn, int m_minNeighborToDie, int m_maxNeighborToDie);
        int getHeight() const;
        int getWidth() const;
        int getMaxIterations() const;
        Grid::GridType getGridType() const;
        int getExactNeighborToBorn() const;
        int getMinNeighborToDie() const;
        int getMaxNeighborToDie() const;
    };
}


#endif //PARAMS_HPP
