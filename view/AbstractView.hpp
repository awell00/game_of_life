//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef VIEW_HPP
#define VIEW_HPP
#include "../controller/AbstractController.hpp"

namespace Controller
{
    class AbstractController;
}

namespace View{
    class AbstractView {
    protected:
        bool running{};
        Controller::AbstractController* controller{};
        AbstractView();
    public:
        virtual void render() = 0;
        bool isRunning();
        virtual ~AbstractView() = default;
    };
}



#endif //VIEW_HPP
