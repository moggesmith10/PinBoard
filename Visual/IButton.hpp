//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IBUTTON_HPP
#define PINBOARD_IBUTTON_HPP


#include "../Utilites/Globals.hpp"
#include "../Utilites/EventResponse.hpp"
#include "IEventHandler.hpp"
#include "IDrawable.hpp"

class IButton : public IEventHandler, public IDrawable{
public:
    virtual bool isHovered(sf::Vector2f position) = 0;

protected:
    Globals *globals;
};


#endif //PINBOARD_IBUTTON_HPP
