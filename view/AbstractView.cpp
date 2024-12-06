//
// Created by Robin Derenty on 03/12/2024.
//

#include "AbstractView.hpp"

namespace View
{
    AbstractView::AbstractView(Controller::AbstractController* m_controller) : controller(m_controller){}
    bool AbstractView::isRunning(){return running;}
}