//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_ICONTEXTMENY_HPP
#define PINBOARD_ICONTEXTMENY_HPP

#include "../Utilites/Globals.hpp"
#include "IDrawable.hpp"
#include "../Utilites/EventResponse.hpp"

class IContextMenu : public IDrawable {
    std::vector<sf::Shape> shapes;
public:
    virtual void handleEvent(sf::Event event, EventResponse *response) = 0;

protected:
    Globals *globals;
};

#endif //PINBOARD_ICONTEXTMENY_HPP
