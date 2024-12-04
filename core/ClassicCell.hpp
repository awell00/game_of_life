//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CLASSICCELL_HPP
#define CLASSICCELL_HPP

#include "AbstractCell.hpp"
namespace Cell
{
    class ClassicCell final : public AbstractCell {
        friend class CellFactory;
    private:
        ClassicCell(bool m_alive, const int m_position[2]);
    public:
        void changeLifeState() override;
    };

}



#endif //CLASSICCELL_HPP
