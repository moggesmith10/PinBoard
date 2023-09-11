//
// Created by hakkerboi on 9/10/23.
//

#ifndef PINBOARD_IEVENTHANDLER_HPP
#define PINBOARD_IEVENTHANDLER_HPP


#include <SFML/Window/Event.hpp>
#include "../Utilites/EventResponse.hpp"

class IEventHandler {
public:
    virtual void handleEvent(sf::Event event, EventResponse *response) = 0;
};


#endif //PINBOARD_IEVENTHANDLER_HPP
