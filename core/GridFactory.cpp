//
// Created by Robin Derenty on 03/12/2024.
//

#include "GridFactory.hpp"

#include <iostream>

#include "ClassicGrid.hpp"
#include "ToricGrid.hpp"

namespace Grid
{
    AbstractGrid* GridFactory::createGrid(GridType m_cellType, int m_gridHeight, int m_gridWidth)
    {
        switch (m_cellType)
        {
        case CLASSIC:
            return new ClassicGrid(m_gridHeight, m_gridWidth);
        case TORIC:
            return new ToricGrid(m_gridHeight, m_gridWidth);
        default:
            return new ClassicGrid(m_gridHeight, m_gridWidth);
        }
    }

}
