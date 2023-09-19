//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP
#define PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP


#include <SFML/Graphics.hpp>
#include "../../IContextMenu.hpp"
#include "../../../Utilites/Globals.hpp"
#include "../../IContextMenuItem.hpp"
#include "DefaultButton.hpp"
#include "../../../Windows/IMainWindow.hpp"
#include "DefaultColorSelector.hpp"

class DefaultMainWindowContextMenu : public IContextMenu {
public:
    DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position, Globals *globals,
                                 IMainWindow *mainWindow, u_char context, sf::Color connectionColor);

    void draw(sf::RenderWindow *renderWindow) override;

    ~DefaultMainWindowContextMenu() override;

    void handleEvent(sf::Event event, EventResponse *response) override;

    void move(sf::Vector2f toMove) override;

    sf::RectangleShape background;
    sf::RenderWindow *renderWindow;
    IMainWindow *mainWindow;
    DefaultButton addTextNodeButton;
    DefaultButton addImageNodeButton;
    DefaultButton deleteNodesButton;
    DefaultButton deleteConnectionsButton;
    DefaultButton deleteBothButton;
    DefaultButton saveLoadButton;
    DefaultColorSelector redColorSelector;
    DefaultColorSelector blueColorSelector;
    DefaultColorSelector greenColorSelector;
    DefaultColorSelector yellowColorSelector;
    DefaultColorSelector orangeColorSelector;
    DefaultColorSelector purpleColorSelector;

    u_char context;
};


#endif //PINBOARD_DEFAULTMAINWINDOWCONTEXTMENU_HPP
