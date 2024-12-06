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
        this->view = new View::ConsoleView(this);
    }

    void ConsoleController::run()
    {
        this->view->render();
        std::string outputPath;
        std::string outputDirectory = std::filesystem::current_path();
        outputDirectory += "/output";
        Utils::File::createDirectory(outputDirectory);
        for (int i = 0; i < this->params->getMaxIterations() ; i++)
        {
            runAlgorithm();
            outputPath =  std::filesystem::current_path();
            outputPath += "/output/outputFile" + std::to_string(i) + ".txt";
            Utils::TxtFile file(outputPath);
            file.writeGrid(this->grid);
        }
    }

    ConsoleController::~ConsoleController()
    {
        delete this->file;
        delete this->params;
    }

}
