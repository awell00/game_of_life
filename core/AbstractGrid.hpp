//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef ABSTRACTGRID_HPP
#define ABSTRACTGRID_HPP
#include <vector>

#include "AbstractCell.hpp"
#include "File.hpp"

namespace Grid
{
    enum GridType
    {
        CLASSIC,
        TORIC
    };

    class AbstractGrid {
    protected:
        int gridHeight;
        int gridWidth;
        Cell::AbstractCell* **grid;
        std::vector<Cell::AbstractCell*> aliveCells;
        std::vector<Cell::AbstractCell*> toModifiateCells;
        AbstractGrid(int m_gridHeight, int m_gridWidth);
    public:
        virtual void generateNewCells() = 0;
        virtual void generateNewCells(Utils::File* startFile) = 0;
        void toggleCells();
        virtual void checkSameGrids() = 0;
        virtual ~AbstractGrid();
    };
}



#endif //ABSTRACTGRID_HPP
