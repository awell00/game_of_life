//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef CONSOLECONTROLLER_HPP
#define CONSOLECONTROLLER_HPP
#include "AbstractController.hpp"


namespace Controller
{
    class ConsoleController : public AbstractController
    {
    public:
        explicit ConsoleController(std::string m_filePath);
        void run() override;
        ~ConsoleController() override;
    };
}


#endif //CONSOLECONTROLLER_HPP
