//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_ICONTEXTMENUITEM_HPP
#define PINBOARD_ICONTEXTMENUITEM_HPP


#include "../Utilites/Globals.hpp"
#include "../Utilites/EventResponse.hpp"
#include "IEventHandler.hpp"

class IContextMenuItem : public IEventHandler{
public:
    virtual bool isHovered(sf::Vector2f position) = 0;

    virtual void draw() = 0;

protected:
    Globals *globals;
};


#endif //PINBOARD_ICONTEXTMENUITEM_HPP
