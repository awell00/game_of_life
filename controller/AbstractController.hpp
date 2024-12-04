//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "../core/Algorithm.hpp"
#include "../core/Params.hpp"
#include "../core/TxtFile.hpp"
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
        Utils::TxtFile* file{};
        Grid::AbstractGrid* grid{};
        Utils::Algorithm* algorithm{};
        AbstractController();
    public:
        virtual void run() = 0;
        virtual void init(std::string filePath);
        virtual ~AbstractController();
    };
}




#endif //CONTROLLER_HPP
