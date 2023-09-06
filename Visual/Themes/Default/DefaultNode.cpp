//
// Created by hakkerboi on 9/5/23.
//

#include "DefaultNode.hpp"
#include "DefaultTextBox.hpp"

void DefaultNode::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    title->draw(renderWindow);
    content->draw(renderWindow);
}

DefaultNode::DefaultNode(sf::Vector2f position, Globals *globals) {
    background = sf::RectangleShape(sf::Vector2f(400, 400));
    background.setFillColor(sf::Color(160, 150, 150));
    background.setPosition(position);
    title = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 10));
    content = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 50));
}

void DefaultNode::handleEvents(sf::Event event, EventResponse *response) {
    EventResponse* internalResponse = new EventResponse();
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (background.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
            title->handleEvent(event, internalResponse);
            if(internalResponse->getPress()){
                response->setSelectedTextBox(title);
            }
            internalResponse->clear();
            content->handleEvent(event, internalResponse);
            if(internalResponse->getPress()){
                response->setSelectedTextBox(content);
            }
        }
    }
    else{
        title->handleEvent(event, internalResponse);
        content->handleEvent(event, internalResponse);
    }
    delete internalResponse;
}
