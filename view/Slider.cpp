#include "Slider.h"

#include <__filesystem/operations.h>

Slider::Slider(float x, float y)
{
    xCord = x;
    yCord = y;
    axisHeight = 20; // Double the height
    axisWidth = 200; // Double the width
    sliderWidth = 55; // Double the width
    sliderHeight = 80; // Double the height

    if (!handCursor.loadFromSystem(sf::Cursor::Hand))
        std::cout << "Error loading hand cursor\n";

    if (!arrowCursor.loadFromSystem(sf::Cursor::Arrow))
        std::cout << "Error loading arrow cursor\n";

    text.setFont(font);
    text.setFillColor(sf::Color::White);

    axis.setPosition(x, y);
    axis.setOrigin(0, axisHeight / 2);
    axis.setSize(sf::Vector2f(axisWidth, axisHeight));
    axis.setFillColor(sf::Color(162, 162, 162));

    slider.setPosition(x, y);
    slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
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
    bool isMouseOverSlider = slider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

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
            slider.setPosition(sf::Mouse::getPosition(window).x, yCord);
            sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
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

void Slider::setSliderPercentValue(float newPercentValue)
{
	if (newPercentValue >= 0 && newPercentValue <= 100)
	{
		sliderValue = newPercentValue / 100 * maxValue;
		slider.setPosition(xCord + (axisWidth * newPercentValue / 100), yCord);
	}
}

void Slider::draw(sf::RenderWindow &window)
{
	logic(window);
	window.draw(returnText(xCord - 30, yCord - 20, std::to_string(minValue), 30));
	window.draw(axis);
	window.draw(returnText(xCord + axisWidth + 15, yCord - 20, std::to_string(maxValue), 30));
	window.draw(slider);

	// Calculate the position to center the text on top of the slider
	float textX = slider.getPosition().x - sliderWidth / 2 + 22.5;
	float textY = slider.getPosition().y - sliderHeight + 25; // Adjust the offset as needed

	window.draw(returnText(textX, textY, std::to_string((int)sliderValue), 25));
}

void Slider::setNewPosition(float x, float y)
{
	xCord = x;
	yCord = y;
	axisHeight = 20; // Double the height
	axisWidth = 200; // Double the width
	sliderWidth = 55; // Double the width
	sliderHeight = 80; // Double the height

	std::string basePath = std::filesystem::current_path();

	if (!font.loadFromFile( basePath + "/../../../assets/font.otf"))
		std::cout << "Error loading font\n";

	if (!sliderTexture.loadFromFile(basePath + "/../../../assets/slide.png")) // Load the texture
		std::cout << "Error loading slider texture\n";

	if (!handCursor.loadFromSystem(sf::Cursor::Hand))
		std::cout << "Error loading hand cursor\n";

	if (!arrowCursor.loadFromSystem(sf::Cursor::Arrow))
		std::cout << "Error loading arrow cursor\n";

	text.setFont(font);
	text.setFillColor(sf::Color::White);

	axis.setPosition(x, y);
	axis.setOrigin(0, axisHeight / 2);
	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
	axis.setFillColor(sf::Color(162, 162, 162));

	slider.setPosition(x, y);
	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
	slider.setTexture(&sliderTexture); // Apply the texture
}
