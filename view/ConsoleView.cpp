//
// Created by Robin Derenty on 04/12/2024.
//

#include "ConsoleView.hpp"

#include <iostream>


namespace View
{
    ConsoleView::ConsoleView() = default;

    void ConsoleView::render()
    {
        std::cout << "Console Mod" << std::endl;
        std::cout << "Saving Files..." << std::endl;
    }


}
