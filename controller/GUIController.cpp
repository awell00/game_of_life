//
// Created by Robin Derenty on 03/12/2024.
//

#include "GUIController.hpp"
#include <SFML/Graphics.hpp>
#include <nfd.h>

#include <iostream>

#include "../core/ClassicCell.hpp"
#include "../view/GUIView.hpp"


namespace Controller
{

    GUIController::GUIController(std::string m_filePath)
    {
        this->createGUI();
        this->view = new View::GUIView(this, this->params->getWidth(), this->params->getHeight());
    }

    void GUIController::createGUI()
    {
        this->init(this->view->getFilePath());
    }


    void GUIController::handleButton(Cell::AbstractCell* cell, std::string button)
    {
        if (button == "leftClick")
        {
            cell->changeLifeState();
        }
    }


    void GUIController::run()
    {
        this->view->render();
    }

}
