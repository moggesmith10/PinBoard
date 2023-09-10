//
// Created by hakkerboi on 9/5/23.
//

#include "DefaultNode.hpp"
#include "DefaultTextBox.hpp"

void DefaultNode::draw(sf::RenderWindow *renderWindow) {
    if(selected){
        renderWindow->draw(border);
    }
    renderWindow->draw(background);
    title->draw(renderWindow);
    content->draw(renderWindow);
}

DefaultNode::DefaultNode(sf::Vector2f position, Globals *globals) {
    border = sf::RectangleShape(sf::Vector2f(500, 500));
    border.setFillColor(sf::Color(100, 100, 100));
    border.setPosition(position);
    background = sf::RectangleShape(sf::Vector2f(490, 490));
    background.setFillColor(sf::Color(160, 150, 150));
    background.setPosition(position.x + 5, position.y + 5);
    title = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 10));
    content = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 50));
    center = sf::Vector2f(position.x + 250, position.y + 250);
}

void DefaultNode::handleEvent(sf::Event event, EventResponse *response) {
    EventResponse* internalResponse = new EventResponse();
    if (event.type == sf::Event::MouseButtonPressed){
        if(background.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
        if(event.mouseButton.button == sf::Mouse::Left) {
                title->handleEvent(event, internalResponse);
                if (internalResponse->getPress()) {
                    response->setSelectTextBox(title);
                }
                internalResponse->clear();
                content->handleEvent(event, internalResponse);
                if (internalResponse->getPress()) {
                    response->setSelectTextBox(content);
            }
        }
        response->setPress(true);
        }
    }
    else{
        title->handleEvent(event, internalResponse);
        content->handleEvent(event, internalResponse);
    }

    if(event.type == sf::Event::MouseButtonReleased){
        if(event.mouseButton.button == sf::Mouse::Left){
            if(background.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
                response->setConnectTo(this);
            }
        }
    }

    delete internalResponse;
}
