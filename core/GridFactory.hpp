//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef GRIDFACTORY_HPP
#define GRIDFACTORY_HPP
#include "AbstractGrid.hpp"

namespace Grid
{
    class GridFactory {
    public:
        static AbstractGrid* createGrid(GridType m_cellType, int m_gridHeight, int m_gridWidth);
    };
}



#endif //GRIDFACTORY_HPP
