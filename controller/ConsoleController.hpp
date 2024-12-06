//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CONSOLECONTROLLER_HPP
#define CONSOLECONTROLLER_HPP

#include "AbstractController.hpp"
#include "../view/ConsoleView.hpp"

namespace View
{
    class ConsoleView;
}


namespace Controller
{
    class ConsoleController : public AbstractController
    {
    private:
        View::ConsoleView* view;
    public:
        explicit ConsoleController(std::string m_filePath);
        void run() override;
        ~ConsoleController() override;
    };
}


#endif //CONSOLECONTROLLER_HPP
