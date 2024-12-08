//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef GUICONTROLLER_HPP
#define GUICONTROLLER_HPP
#include "AbstractController.hpp"
#include "../view/GUIView.hpp"

namespace View
{
    class GUIView;
}

namespace Controller
{
    class GUIController : public AbstractController
    {
    private:
        View::GUIView* view{};
    public:
        explicit GUIController();
        void run() override;
        void createGUI();
        void handleButton(Cell::AbstractCell* cell, std::string button) override;
    };
}



#endif //GUICONTROLLER_HPP
