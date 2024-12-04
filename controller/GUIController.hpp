//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef GUICONTROLLER_HPP
#define GUICONTROLLER_HPP
#include "AbstractController.hpp"

namespace Controller
{
    class GUIController : public AbstractController
    {
    public:
        GUIController();
        void run() override;
        void init() override;
        void handleButton();
    };
}



#endif //GUICONTROLLER_HPP
