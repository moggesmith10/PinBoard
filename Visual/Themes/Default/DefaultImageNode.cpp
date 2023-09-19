//
// Created by hakkerboi on 9/18/23.
//

#include "DefaultImageNode.hpp"

void DefaultImageNode::draw(sf::RenderWindow *renderWindow) {
    if (selected){
        renderWindow->draw(border);
    }
    renderWindow->draw(sprite);
}

DefaultImageNode::DefaultImageNode(sf::Texture *texture, sf::Vector2f position) {
    this->texture = texture;
    sprite = sf::Sprite();
    sprite.setTexture(*texture);
    sprite.setPosition(position);
    border = sf::RectangleShape();
    border.setFillColor(sf::Color(100, 100, 100));
    border.setPosition(position - sf::Vector2f(5, 5));
    border.setSize(sf::Vector2f(texture->getSize().x + 10, texture->getSize().y + 10));

    center = position + sf::Vector2f(texture->getSize().x / 2, texture->getSize().y / 2);
}

void DefaultImageNode::move(sf::Vector2f toMove) {
    sprite.move(toMove);
    border.move(toMove);
    center += toMove;
}

void DefaultImageNode::handleEvent(sf::Event event, EventResponse *response) {

    if(event.type == sf::Event::MouseButtonPressed){
        if(sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
            response->setPress(true);
        }
    }
    if(event.type == sf::Event::MouseButtonReleased){
        if(event.mouseButton.button == sf::Mouse::Left){
            if(sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
                response->setConnectTo(this);
            }
        }
    }
}
