//
// Created by hakkerboi on 10/11/23.
//

#ifndef PINBOARD_WARMCONTEXTMENU_HPP
#define PINBOARD_WARMCONTEXTMENU_HPP


#include "../../IContextMenu.hpp"
#include "WarmButton.hpp"

class WarmContextMenu : public IContextMenu {
public:
    WarmContextMenu(Globals *globals);

    void handleEvent(sf::Event event, EventResponse *response) override;

    void draw(sf::RenderWindow* renderWindow) override;

    void move(sf::Vector2f toMove) override;

    ~WarmContextMenu();
private:
    sf::RectangleShape background;
    WarmButton *createTextNodeButton = nullptr;
};


#endif //PINBOARD_WARMCONTEXTMENU_HPP
