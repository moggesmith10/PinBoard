//
// Created by hakkerboi on 9/11/23.
//

#include "DefaultColorSelector.hpp"

void DefaultColorSelector::draw(sf::RenderWindow *renderWindow) {
    if(selected) {
        renderWindow->draw(background);
    }
    renderWindow->draw(colorCircle);
}

DefaultColorSelector::DefaultColorSelector(sf::Vector2f position, sf::Color color, bool selected) {
    this->selected = selected;

    colorCircle = sf::CircleShape();
    colorCircle.setRadius(16);
    colorCircle.setFillColor(color);
    colorCircle.setOrigin(8, 8);
    colorCircle.setPosition(position);

    background = sf::CircleShape();
    background.setRadius(19);
    background.setOrigin(11, 11);
    background.setPosition(position);
    background.setFillColor(sf::Color(255, 255, 255));
}

void DefaultColorSelector::handleEvent(sf::Event event, EventResponse *response) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(colorCircle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
            response->setPress(true);
        }
    }
}
