//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CLASSICGRID_HPP
#define CLASSICGRID_HPP
#include "AbstractGrid.hpp"
#include "GridFactory.hpp"

namespace Grid
{
    class ClassicGrid final : public AbstractGrid{
        friend class Grid::GridFactory;
    private:
        ClassicGrid(int m_gridHeight, int m_gridWidth);
    public:
        void generateNewCells(int exactNeighborToBorn, int minNeighborToDie, int maxNeighborToDie) override;
        void generateNewCells(Utils::File* file);
    };
}




#endif //CLASSICGRID_HPP
