//
// Created by hakkerboi on 9/6/23.
//

#ifndef PINBOARD_DEFAULTTEXTBOX_HPP
#define PINBOARD_DEFAULTTEXTBOX_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include "../../ITextBox.hpp"
#include "../../../Utilites/Globals.hpp"

class DefaultTextBox : public ITextBox {
public:
    DefaultTextBox(Globals *globals, sf::Vector2f position, std::string content = "UNSET");

    void handleEvent(sf::Event event, EventResponse *response) override;

    void draw(sf::RenderWindow *renderWindow) override;

    void move(sf::Vector2f) override;
private:
    bool empty = false;
};


#endif //PINBOARD_DEFAULTTEXTBOX_HPP
