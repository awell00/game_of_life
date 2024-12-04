//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractController.hpp"
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

        Grid::GridFactory::createGrid(this->params->getGridType(), this->params->getHeight(), this->params->getWidth());
        delete parser;
        delete this->file;
    }
    AbstractController::~AbstractController()
    {

    }

}
