//
// Created by hakkerboi on 9/6/23.
//

#ifndef PINBOARD_ITEXTBOX_HPP
#define PINBOARD_ITEXTBOX_HPP


#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>
#include "IDrawable.hpp"
#include "../Utilites/EventResponse.hpp"

class ITextBox : public IDrawable{
public:
    virtual void handleEvent(sf::Event event, EventResponse *response) = 0;
    virtual void draw(sf::RenderWindow *renderWindow) override = 0;
    bool isFocused = false;
    sf::Text text;
    std::string content;
};


#endif //PINBOARD_ITEXTBOX_HPP
