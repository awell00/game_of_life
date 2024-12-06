//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractController.hpp"

#include <iostream>

#include "../core/TxtParser.hpp"
#include "../core/GridFactory.hpp"

namespace Utils
{
    class Parser;
    class TxtParser;
}

namespace Controller {
    AbstractController::AbstractController() = default;

    void AbstractController::init(std::string filePath)
    {

        this->file = new Utils::TxtFile(filePath);

        Utils::Params* params = nullptr;
        Utils::Parser* parser = new Utils::TxtParser(this->file);

        params = parser->parseParams();
        this->params = params;

        this->grid = Grid::GridFactory::createGrid(this->params->getGridType(), this->params->getHeight(), this->params->getWidth());

        this->grid->generateNewCells(this->file);

        this->algorithm = new Utils::Algorithm(grid, this->params->getExactNeighborToBorn(), this->params->getMinNeighborToDie(), this->params->getMaxNeighborToDie(), this->params->getMaxIterations());

        delete parser;
        delete this->file;
    }
    AbstractController::~AbstractController()
    {
        delete this->algorithm;
        delete this->file;
        delete this->grid;
        delete this->params;
    }

    bool AbstractController::runAlgorithm()
    {
        return this->algorithm->generateNewGrid();
    }

    Grid::AbstractGrid* AbstractController::getGrid()
    {
        return this->grid;
    }


}
