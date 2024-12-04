//
// Created by Robin Derenty on 03/12/2024.
//

#include "ConsoleController.hpp"

#include <iostream>

#include "../core/GridFactory.hpp"
#include "../core/TxtFile.hpp"
#include "../core/TxtParser.hpp"

namespace Controller
{
    ConsoleController::ConsoleController(std::string m_filePath)
    {
        this->ConsoleController::init(m_filePath);
    }

    void ConsoleController::run()
    {
        for (int i = 0; i < this->params->getMaxIterations() ; i++)
        {

        }
    }

    ConsoleController::~ConsoleController()
    {
        delete this->file;
        delete this->params;
    }

}
