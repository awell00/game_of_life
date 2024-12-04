//
// Created by Robin Derenty on 03/12/2024.
//

#include "ObstacleCell.hpp"

namespace Cell
{
    ObstacleCell::ObstacleCell(bool m_alive, const int m_position[2]) : AbstractCell(m_alive, m_position){}

    void ObstacleCell::changeLifeState(){;}
}


