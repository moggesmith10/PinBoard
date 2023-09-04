//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP
#define PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP


#include <SFML/Graphics.hpp>
#include "../../IContextMenuItem.hpp"

class DefaultMainWindowContextMenuItem : public IContextMenuItem {
public:
    bool isHovered(sf::Vector2f position) override;
    void draw() override;
    DefaultMainWindowContextMenuItem();
    DefaultMainWindowContextMenuItem(std::string text, Globals* globals, sf::RenderWindow *renderWindow, sf::Vector2f position);
private:
    sf::RenderWindow *renderWindow;
    sf::RectangleShape background;
    sf::Text text;
};


#endif //PINBOARD_DEFAULTMAINWINDOWCONTEXTMENUITEM_HPP
