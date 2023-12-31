//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP
#define PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP


#include <SFML/Graphics.hpp>
#include "../../IButton.hpp"

class DefaultButton : public IButton {
public:
    bool isHovered(sf::Vector2f position) override;

    void draw(sf::RenderWindow *renderWindow) override;

    DefaultButton();

    DefaultButton(std::string text, Globals *globals, sf::RenderWindow *renderWindow,
                  sf::Vector2f position);

    void handleEvent(sf::Event event, EventResponse *response) override;

    void move(sf::Vector2f toMove) override;

private:
    sf::RenderWindow *renderWindow;
    sf::RectangleShape background;
    sf::Text text;
};


#endif //PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP
