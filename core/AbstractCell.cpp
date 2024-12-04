//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractCell.hpp"
namespace Cell
{
    AbstractCell::AbstractCell(bool m_alive, const int m_position[2])
    {
        this->alive = m_alive;
        this->position[0] = m_position[0];
        this->position[1] = m_position[1];
    }

    bool AbstractCell::getAlive() const
    {
        return this->alive;
    }

    int* AbstractCell::getPosition()
    {
        return this->position;
    }
}



