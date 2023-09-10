//
// Created by hakkerboi on 9/6/23.
//

#ifndef PINBOARD_ITEXTBOX_HPP
#define PINBOARD_ITEXTBOX_HPP


#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>
#include "IDrawable.hpp"
#include "../Utilites/EventResponse.hpp"
#include "IEventHandler.hpp"

class ITextBox : public IDrawable, public IEventHandler {
public:
    bool isFocused = false;
    sf::Text text;
    std::string content;
};


#endif //PINBOARD_ITEXTBOX_HPP
