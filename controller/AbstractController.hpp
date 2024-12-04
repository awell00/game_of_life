//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "../core/Algorithm.hpp"
#include "../core/Params.hpp"
#include "../view/AbstractView.hpp"


namespace View
{
    class AbstractView;
}

namespace Controller
{
    class AbstractController {
    protected:
        View::AbstractView* view{};
        Utils::Params* params{};
        Utils::File* file{};
        Grid::AbstractGrid* grid{};
        Utils::Algorithm* algorithm{};
        AbstractController();
    public:
        virtual void run() = 0;
        virtual void init() = 0;
        virtual ~AbstractController();
    };
}




#endif //CONTROLLER_HPP
