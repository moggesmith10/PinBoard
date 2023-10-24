//
// Created by hakkerboi on 10/16/23.
//

#ifndef PINBOARD_WARMBUTTON_HPP
#define PINBOARD_WARMBUTTON_HPP


#include "../../IButton.hpp"

class WarmButton : public IButton {
public:
    WarmButton(Globals *globals, sf::Vector2f position, sf::Vector2f size, std::string text);

    void handleEvent(sf::Event event, EventResponse *response) override;

    void draw(sf::RenderWindow* renderWindow) override;

    void move(sf::Vector2f toMove) override;

    bool isHovered(sf::Vector2f position) override;

    ~WarmButton();
private:
    sf::RectangleShape background;
    sf::Text text;
};


#endif //PINBOARD_WARMBUTTON_HPP
