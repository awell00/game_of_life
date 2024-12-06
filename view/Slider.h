#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Slider
{
    sf::RectangleShape slider;
    sf::RectangleShape axis;
    sf::Font font;
    sf::Text text;
    sf::Texture sliderTexture;
    sf::Cursor handCursor;
    sf::Cursor arrowCursor;
    int minValue{};
    int maxValue{};
    int xCord;
    int yCord;
    int axisWidth;
    int axisHeight;
    int sliderWidth;
    int sliderHeight;
    float sliderValue{};

public:
    Slider(float x, float y);
    Slider(const Slider& other);
    Slider& operator=(const Slider& other);
    sf::Text returnText(float x, float y, std::string z, int fontSize);
    void create(float min, float max);
    void logic(sf::RenderWindow &window);
    float getSliderValue();
    void setSliderValue(float newValue);
    void setSliderPercentValue(float newPercentValue);
    void setNewPosition(float x, float y);
    void draw(sf::RenderWindow & window);
};

