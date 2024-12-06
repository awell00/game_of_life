//
// Created by Robin Derenty on 04/12/2024.
//

#include "ConsoleView.hpp"

#include <iostream>


namespace Controller
{
    class GUIController;
}

namespace View
{
    ConsoleView::ConsoleView(Controller::AbstractController* m_controller) : AbstractView(m_controller){}

    void ConsoleView::render()
    {
        std::cout << "Console Mod" << std::endl;
        std::cout << "Saving Files..." << std::endl;
    }


}
