//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef TORICGRID_HPP
#define TORICGRID_HPP
#include "AbstractGrid.hpp"
#include "GridFactory.hpp"

namespace Grid
{
    class ToricGrid final : public AbstractGrid{
        friend class Grid::GridFactory;
    private:
        ToricGrid(int m_gridHeight, int m_gridWidth);
    public:

        void generateNewCells(int exactNeighborToBorn, int minNeighborToDie, int maxNeighborToDie) override;
        void generateNewCells(Utils::File* file);
    };

}



#endif //TORICGRID_HPP
