//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef OBSTACLECELL_HPP
#define OBSTACLECELL_HPP
#include "AbstractCell.hpp"
namespace Cell
{
    class ObstacleCell final : public AbstractCell{
        friend class CellFactory;
    private:
        ObstacleCell(bool m_alive, const int m_position[2]);
    public:
        void changeLifeState() override;
    };
}

#endif //OBSTACLECELL_HPP
