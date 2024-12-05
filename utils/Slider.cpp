#include "Slider.hpp"

Slider::Slider(float x, float y)
{
    xCord = x;
    yCord = y;
    axisHeight = 20.0f;
    axisWidth = 200.0f;
    sliderWidth = 55.0f;
    sliderHeight = 80.0f;

    if (!font.loadFromFile("./utils/files/font.otf"))
        std::cout << "Error loading font\n";

    if (!sliderTexture.loadFromFile("./utils/files/slide.png"))
        std::cout << "Error loading slider texture\n";

    if (!handCursor.loadFromSystem(sf::Cursor::Hand))
        std::cout << "Error loading hand cursor\n";

    if (!arrowCursor.loadFromSystem(sf::Cursor::Arrow))
        std::cout << "Error loading arrow cursor\n";

    text.setFont(font);
    text.setFillColor(sf::Color::White);

    axis.setPosition(x, y);
    axis.setOrigin(0.0f, axisHeight / 2.0f);
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(sf::Color(162, 162, 162));

    slider.setPosition(x, y);
    slider.setOrigin(sliderWidth / 2.0f, sliderHeight / 2.0f);
    slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
    slider.setTexture(&sliderTexture); // Apply the texture
}

sf::Text Slider::returnText(float x, float y, std::string z, int fontSize)
{
    text.setCharacterSize(fontSize);
    text.setPosition(x, y);
    text.setString(z);
    return text;
}

void Slider::create(float min, float max)
{
    sliderValue = min;
    minValue = min;
    maxValue = max;
}

void Slider::logic(sf::RenderWindow &window)
{
    bool isMouseOverSlider = slider.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y));

    if (isMouseOverSlider)
    {
        window.setMouseCursor(handCursor);
    }
    else
    {
        window.setMouseCursor(arrowCursor);
    }

    if (isMouseOverSlider && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth)
        {
            slider.setPosition(static_cast<float>(sf::Mouse::getPosition(window).x), yCord);
            sliderValue = minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue));
        }
    }
}

float Slider::getSliderValue()
{
    return sliderValue;
}

void Slider::setSliderValue(float newValue)
{
    if (newValue >= minValue && newValue <= maxValue)
    {
        sliderValue = newValue;
        float diff = maxValue - minValue;
        float diff2 = newValue - minValue;
        float zzz = axisWidth / diff;
        float posX = zzz * diff2;
        posX += xCord;
        slider.setPosition(posX, yCord);
    }
}

void Slider::setSliderPercentValue(const float newPercentValue)
{
    if (newPercentValue >= 0.0f && newPercentValue <= 100.0f)
    {
        sliderValue = newPercentValue / 100.0f * maxValue;
        slider.setPosition(xCord + (axisWidth * newPercentValue / 100.0f), yCord);
    }
}

void Slider::draw(sf::RenderWindow &window)
{
    logic(window);
    window.draw(returnText(xCord - 30.0f, yCord - 20.0f, std::to_string(minValue), 30));
    window.draw(axis);
    window.draw(returnText(xCord + axisWidth + 15.0f, yCord - 20.0f, std::to_string(maxValue), 30));
    window.draw(slider);

    float textX = slider.getPosition().x - sliderWidth / 2.0f + 22.5f;
    float textY = slider.getPosition().y - sliderHeight + 25.0f;

    window.draw(returnText(textX, textY, std::to_string(static_cast<int>(sliderValue)), 25));
}