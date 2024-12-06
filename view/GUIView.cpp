//
// Created by Robin Derenty on 05/12/2024.
//

#include "GUIView.hpp"

#include "nfd.h"

namespace View
{
    GUIView::GUIView(Controller::AbstractController* m_controller, int m_gridWidth, int m_gridHeight) :
    AbstractView(m_controller),
    gridHeight(m_gridHeight),
    gridWidth(m_gridWidth),
    window(sf::VideoMode(10, 10), "Game of Life", sf::Style::Titlebar | sf::Style::Close),
    iterationText("Iterations: 0", font, 55),
    topBarHeight(120),
    topBar(sf::Vector2f(static_cast<float>(window.getSize().x), topBarHeight)),
    slider(10, 10)
    {

        cellSize = 20;
        bottomBarHeight = 100;
        std::string basePath = std::filesystem::current_path();

        window.create(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize + topBarHeight + bottomBarHeight), "Game of Life", sf::Style::Titlebar | sf::Style::Close);


        if (!font.loadFromFile(basePath  + "/../../../assets/font.otf")) {
            std::cerr << "Failed to load font 'font.otf'" << std::endl;
            return;
        }

        topBar.setFillColor(sf::Color::Black);

        iterationText.setFillColor(sf::Color::White);
        iterationText.setPosition(50, 10);

        if (!playTexture.loadFromFile(basePath + "/../../../assets/play.png") || !stopTexture.loadFromFile(basePath + "/../../../assets/pause.png")) {
            std::cerr << "Failed to load control textures" << std::endl;
            return;
        }

        playStopSprite.setPosition((window.getSize().x - playStopSprite.getGlobalBounds().width) / 2, gridHeight * cellSize + topBarHeight + 10);

        if (!handCursor.loadFromSystem(sf::Cursor::Hand) || !arrowCursor.loadFromSystem(sf::Cursor::Arrow)) {
            std::cerr << "Failed to load cursors" << std::endl;
            return;
        }


        if (gridWidth < 35 || gridHeight > 83 || gridWidth > 162 || gridHeight < 3) {
            std::cerr << "Grid dimensions are too small for the slider" << std::endl;
            return;
        }
        slider.setNewPosition(window.getSize().x - 300, 52.5);
        slider.create(1.0f, 10.0f);
        slider.setSliderValue(0.5f);
    }

    void GUIView::renderGrid()
    {
        sf::RectangleShape cell(sf::Vector2f(static_cast<float>(cellSize) - 1.0f, static_cast<float>(cellSize) - 1.0f));
        for (int y = 0; y < gridHeight; ++y) {
            for (int x = 0; x < gridWidth; ++x) {
                if (controller->getGrid()->getCellByPosition(y, x)->getAlive()) {
                    cell.setFillColor(sf::Color::White);
                    cell.setPosition(static_cast<float>(x * cellSize), static_cast<float>(y * cellSize) + topBarHeight);
                    window.draw(cell);
                }
            }
        }
    }


    void GUIView::render()
    {
        running = true;
        sf::Clock clock;
        int iterations = 0;
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) {
                        running = !isRunning();
                        playStopSprite.setTexture(isRunning() ? stopTexture : playTexture);
                    } else if (event.key.code == sf::Keyboard::Left) {
                        slider.setSliderValue(slider.getSliderValue() - 0.1f);
                    } else if (event.key.code == sf::Keyboard::Right) {
                        slider.setSliderValue(slider.getSliderValue() + 0.1f);
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (playStopSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        running = !isRunning();
                        playStopSprite.setTexture(isRunning() ? stopTexture : playTexture);
                    } else {
                        int gridX = mousePos.x / cellSize;
                        int gridY = (mousePos.y - topBarHeight) / cellSize;
                        if (gridX >= 0 && gridX < gridWidth && gridY >= 0 && gridY < gridHeight) {
                            if (event.mouseButton.button == sf::Mouse::Left && !isRunning()) {
                                controller->handleButton(controller->getGrid()->getCellByPosition(gridY, gridX), "leftClick");
                            }
                        }
                    }
                }
            }

            slider.logic(window);

            if (isRunning()) {
                float sleepDuration = 8.0f - (slider.getSliderValue() - 1.0f) * (8.0f - 0.5f) / 9.0f;
                if (clock.getElapsedTime().asSeconds() >= sleepDuration && controller->runAlgorithm()) {
                    ++iterations;
                    iterationText.setString("Iterations: " + std::to_string(iterations));
                    clock.restart();
                }
            }

            window.clear();
            renderGrid();
            window.draw(topBar);
            window.draw(iterationText);
            window.draw(playStopSprite);
            slider.draw(window);
            window.display();
        }
    }

    std::string GUIView::getFilePath()
    {
        if (NFD_Init() != NFD_OKAY) {
            std::cerr << "Failed to initialize Native File Dialog" << std::endl;
            return "";
        }
        nfdu8char_t *outPath = nullptr;
        nfdu8filteritem_t filters[] = {{"Text files", "txt"}};
        nfdopendialogu8args_t args = {filters, 1};
        if (NFD_OpenDialogU8_With(&outPath, &args) == NFD_OKAY) {
            return outPath;
        } else {
            std::cerr << "No file selected or error occurred" << std::endl;
            NFD_Quit();
            return "";
        }
        NFD_FreePathU8(outPath);
        NFD_Quit();
    }

}
