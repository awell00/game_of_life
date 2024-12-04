//
// Created by Robin Derenty on 03/12/2024.
//

#include "ConsoleController.hpp"

#include "../core/GridFactory.hpp"
#include "../core/TxtFile.hpp"

namespace Controller
{
    void ConsoleController::init()
    {
        this->grid = Grid::GridFactory::createGrid(Grid::CLASSIC, 10, 10);
        this->params = new Utils::Params(10, 10, 50, Grid::CLASSIC, 3, 2, 3, 1);
        delete this->file;
    }

    ConsoleController::ConsoleController(std::string m_filePath)
    {
        this->file = new Utils::TxtFile(m_filePath);
        this->ConsoleController::init();
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
        delete this;
    }

}
