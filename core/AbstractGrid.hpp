//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef ABSTRACTGRID_HPP
#define ABSTRACTGRID_HPP
#include <vector>

#include "AbstractCell.hpp"
#include "File.hpp"

namespace Utils
{
    class File;
}

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
        virtual void generateNewCells(int exactNeighborToBorn, int minNeighborToDie, int maxNeighborToDie) = 0;
        void generateNewCells(Utils::File* startFile) const;
        int getHeight() const;
        int getWidth() const;
        void toggleCells() const;
        Cell::AbstractCell* getCellByPosition(int lineIndex, int columnIndex) const;
        bool checkSameGrids() const;
        virtual ~AbstractGrid();
    };
}



#endif //ABSTRACTGRID_HPP
