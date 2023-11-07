//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOW_HPP
#define PINBOARD_DEFAULTMAINWINDOW_HPP


#include "../../IMainWindow.hpp"
#include "../../../Visual/Themes/Default/DefaultMainWindowContextMenu.hpp"
#include "../../../Visual/Themes/Default/DefaultConnection.hpp"

class DefaultMainWindow : public IMainWindow {
public:
    DefaultMainWindow(Globals *globals);

    void handleEvents() override;

    void draw() override;

    sf::Vector2f* lastMousePosition = nullptr;

private:
    void createContextMenu(sf::Vector2f position);
    void deleteConnectionsToNode(INode *node);
    bool isConnectionUnique(INode *node1, INode *node2);
    sf::Color selectedConnectionColor = sf::Color::Red;
};


#endif //PINBOARD_DEFAULTMAINWINDOW_HPP
