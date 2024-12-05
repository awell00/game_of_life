//
// Created by Robin Derenty on 04/12/2024.
//

#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP
#include "AbstractView.hpp"


namespace View
{
    class ConsoleView : public AbstractView{
    public:
        ConsoleView();
        void render() override;
    };
}




#endif //CONSOLEVIEW_HPP
