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
#include "../../../Windows/IMainWindow.hpp"

class DefaultMainWindowContextMenu : public IContextMenu {
public:
    DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position, Globals *globals,
                                 IMainWindow *mainWindow);

    void draw(sf::RenderWindow *renderWindow) override;

    ~DefaultMainWindowContextMenu() override;

    void handleEvent(sf::Event event, EventResponse *response) override;

    sf::RectangleShape background;
    sf::RenderWindow *renderWindow;
    IMainWindow *mainWindow;
    DefaultMainWindowContextMenuItem addNodeButton;
    DefaultMainWindowContextMenuItem deleteNodesButton;
};


#endif //PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP
