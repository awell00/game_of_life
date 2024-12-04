//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CELLFACTORY_HPP
#define CELLFACTORY_HPP
#include "AbstractCell.hpp"

namespace Cell
{
    class CellFactory {
    public:
        static AbstractCell* createCell(CellType m_cellType, bool m_alive, int m_position[2]);
    };
}



#endif //CELLFACTORY_HPP
