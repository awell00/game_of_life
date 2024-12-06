//
// Created by Robin Derenty on 03/12/2024.
//

#include "ClassicCell.hpp"

namespace Cell
{
    ClassicCell::ClassicCell(bool m_alive, const int m_position[2]) : AbstractCell(m_alive, m_position){}

    void ClassicCell::changeLifeState()
    {
            this->alive = !this->alive;
    }
}

