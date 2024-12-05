#ifndef GUIVIEW_H
#define GUIVIEW_H
#include "AbstractView.hpp"
#include "../core/AbstractGrid.hpp"
#include "../core/Params.hpp"
#include <SFML/Graphics.hpp>
#include "../utils/Slider.hpp"

namespace Grid
{
    class AbstractGrid;
}

namespace View
{
    class GUIView final: public AbstractView {
        bool pausePlayButton;
        float timeIterationSlider;
        int nbIterations;
        char changeTypeOfCellule;
        Grid::AbstractGrid* grid;
        Utils::Params params;
        sf::RenderWindow* window;
    public:
        explicit GUIView(View::AbstractView* view, const Utils::Params& params);
        void render(const Utils::Params& params) override;
        void handleEvent(sf::Event& event, sf::RenderWindow& window, sf::Sprite& playStopSprite, bool& isPlaying, sf::Texture& playTexture, sf::Texture& stopTexture, Slider& slider);
        bool isRunning() const;
    };
}

#endif //GUIVIEW_H