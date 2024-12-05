//
// Created by Robin Derenty on 03/12/2024.
//

#include "ConsoleController.hpp"

#include <iostream>

#include "../core/GridFactory.hpp"
#include "../core/TxtFile.hpp"
#include "../core/TxtParser.hpp"
#include "../view/ConsoleView.hpp"

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
            this->grid = this->algorithm->generateNewGrid();
            this->algorithm->setNewGrid(this->grid);
            Utils::TxtFile file("/Users/robin/IDE_Projects/CLionProjects/game_of_life/output.txt");
            file.writeGrid(this->grid);
        }
    }

    ConsoleController::~ConsoleController()
    {
        delete this->file;
        delete this->params;
    }

}
