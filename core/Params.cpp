//
// Created by Robin Derenty on 03/12/2024.
//

#include "Params.hpp"

namespace Utils
{
    Params::Params(int m_height, int m_width, int m_maxIterations, Grid::GridType m_gridType, int m_exactNeighborToBorn, int m_minNeighborToDie, int m_maxNeighborToDie)
    {
        this->height = m_height;
        this->width = m_width;
        this->maxIterations = m_maxIterations;
        this->gridType = m_gridType;
        this->exactNeighborToBorn = m_exactNeighborToBorn;
        this->minNeighborToDie = m_minNeighborToDie;
        this->maxNeighborToDie = m_maxNeighborToDie;
    }

    int Params::getHeight() const {return this->height;}
    int Params::getWidth() const {return this->width;}
    int Params::getMaxIterations() const {return this->maxIterations;}
    Grid::GridType Params::getGridType() const {return this->gridType;}
    int Params::getExactNeighborToBorn() const {return this->exactNeighborToBorn;}
    int Params::getMinNeighborToDie() const {return this->minNeighborToDie;}
    int Params::getMaxNeighborToDie() const {return this->maxNeighborToDie;}










}