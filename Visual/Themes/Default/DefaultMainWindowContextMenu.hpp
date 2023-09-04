//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP
#define PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP


#include <SFML/Graphics.hpp>
#include "../../IContextMeny.hpp"
#include "../../../Utilites/Globals.hpp"
#include "../../IContextMenuItem.hpp"
#include "DefaultMainWindowContextMenuItem.hpp"

class DefaultMainWindowContextMenu : public IContextMenu {
public:
    DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position, Globals *globals);
    void draw() override;
    ~DefaultMainWindowContextMenu() override;
    void handleEvent(sf::Event event) override;
    sf::RectangleShape background;
    sf::RenderWindow *renderWindow;

    DefaultMainWindowContextMenuItem addNodeButton;
};


#endif //PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP
