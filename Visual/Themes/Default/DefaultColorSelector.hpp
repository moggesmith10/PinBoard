//
// Created by hakkerboi on 9/11/23.
//

#ifndef PINBOARD_DEFAULTCOLORSELECTOR_HPP
#define PINBOARD_DEFAULTCOLORSELECTOR_HPP


#include "../../IColorSelector.hpp"

class DefaultColorSelector : public IColorSelector {
public:
    void draw(sf::RenderWindow *renderWindow) override;
    void handleEvent(sf::Event event, EventResponse *response) override;
    DefaultColorSelector(sf::Vector2f position, sf::Color color, bool selected);
    DefaultColorSelector() = default;
private:
    sf::CircleShape colorCircle;
    sf::CircleShape background;
};


#endif //PINBOARD_DEFAULTCOLORSELECTOR_HPP
