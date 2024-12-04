//
// Created by Robin Derenty on 03/12/2024.
//

#include "CellFactory.hpp"

#include "ClassicCell.hpp"
#include "ObstacleCell.hpp"
namespace Cell
{
    AbstractCell* CellFactory::createCell(CellType m_cellType, bool m_alive, int m_position[2])
    {
        switch (m_cellType)
        {
        case (CLASSIC):
            return new ClassicCell(m_alive, m_position);
        case (OBSTACLE):
            return new ObstacleCell(m_alive, m_position);
        default:
            return nullptr;
        }
    }
}

