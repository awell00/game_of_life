
#include <iostream>

#include "controller/ConsoleController.hpp"
#include "controller/GUIController.hpp"

int main(int argc, char *argv[])
{
    Controller::AbstractController* controller;

    if (argc > 1 && (strcmp(argv[1],"-c") == 0))
    {
        if (argc > 2)
        {
            controller = new Controller::ConsoleController(argv[2]);
        }
        else
        {
            std::cout << "What is the path to initial file ?" << std::endl;
            std::string filePath;
            std::cin >> filePath;
            controller = new Controller::ConsoleController(filePath);
        }
    }
    else
    {
        controller = new Controller::GUIController();
    }
    controller->run();
    return 0;
}
