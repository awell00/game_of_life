//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef ABSTRACTCELL_HPP
#define ABSTRACTCELL_HPP
#include <memory>

namespace Cell
{
    enum CellType
    {
        CLASSIC,
        OBSTACLE
    };

    class AbstractCell {
    protected:
        bool alive;
        int position[2]{};
        AbstractCell(bool m_alive, const int m_position[2]);
    public:
        bool getAlive() const;
        int* getPosition();
        virtual void changeLifeState() = 0;
        virtual ~AbstractCell() = default;
    };

}


#endif //ABSTRACTCELL_HPP
