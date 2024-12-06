//
// Created by Robin Derenty on 05/12/2024.
//

#ifndef GUIVIEW_HPP
#define GUIVIEW_HPP
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "AbstractView.hpp"
#include "Slider.h"
#include "../controller/GUIController.hpp"


namespace View
{
    class GUIView : public AbstractView {
    private:
        int cellSize;
        int topBarHeight;
        int bottomBarHeight;
        int gridWidth;
        int gridHeight;
        sf::Font font;
        sf::RenderWindow window;
        sf::RectangleShape topBar;
        sf::Text iterationText;
        sf::Texture playTexture, stopTexture;;
        sf::Sprite playStopSprite;
        sf::Cursor handCursor, arrowCursor;
        sf::Clock clock;
        Slider slider;
    public:
        GUIView(Controller::AbstractController* controller, int gridWidth, int gridHeight);
        std::string getFilePath();
        void renderGrid();
        void render() override;
    };
}




#endif //GUIVIEW_HPP
