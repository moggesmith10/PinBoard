//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_ICONTEXTMENUITEM_HPP
#define PINBOARD_ICONTEXTMENUITEM_HPP


#include "../Utilites/Globals.hpp"
#include "../Utilites/EventResponse.hpp"

class IContextMenuItem {
public:
    virtual bool isHovered(sf::Vector2f position) = 0;

    /**
     * @brief Handles events for the context menu item
     * @param event Event
     * @return Was item clicked
     */
    virtual void handleEvent(sf::Event event, EventResponse *response) = 0;

    virtual void draw() = 0;

protected:
    Globals *globals;
};


#endif //PINBOARD_ICONTEXTMENUITEM_HPP
