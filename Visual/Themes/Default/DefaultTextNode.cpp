//
// Created by hakkerboi on 9/5/23.
//

#include "DefaultTextNode.hpp"
#include "DefaultTextBox.hpp"

void DefaultTextNode::draw(sf::RenderWindow *renderWindow) {
    if(selected){
        renderWindow->draw(border);
    }
    renderWindow->draw(background);
    title->draw(renderWindow);
    content->draw(renderWindow);
}

DefaultTextNode::DefaultTextNode(sf::Vector2f position, Globals *globals) {
    border = sf::RectangleShape(sf::Vector2f(300, 300));
    border.setFillColor(sf::Color(100, 100, 100));
    border.setPosition(position);
    background = sf::RectangleShape(sf::Vector2f(290, 290));
    background.setFillColor(sf::Color(160, 150, 150));
    background.setPosition(position.x + 5, position.y + 5);
    title = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 10));
    content = new DefaultTextBox(globals, sf::Vector2f(position.x + 10, position.y + 50));
    center = position + sf::Vector2f(150, 150);
}

void DefaultTextNode::handleEvent(sf::Event event, EventResponse *response) {
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

void DefaultTextNode::move(sf::Vector2f toMove) {
    border.setPosition(border.getPosition() + toMove);
    background.setPosition(background.getPosition() + toMove);
    title->move(toMove);
    content->move(toMove);
    center += toMove;
}

bool DefaultTextNode::deserialize(std::vector<std::byte> data) {
    std::string info = (char *) data.data();
    std::string theme = info.substr(info.find(':'), info.find(';'));
    info = info.substr(info.find(';') + 1);
    std::string position = info.substr(info.find(':'), info.find(';'));
    info = info.substr(info.find(';') + 1);

    std::string x = position.substr(info.find(':'), position.find(','));
    std::string y = position.substr(position.find(',') + 1);

    border.setPosition(std::stof(x), std::stof(y));

    std::string title = info.substr(info.find(':'), info.find(';'));
    info = info.substr(info.find(';') + 1);

    std::string content = info.substr(0, info.find(';'));

    this->title->text.setString(title);
    this->content->text.setString(content);

    return true;
}

std::vector<std::byte> DefaultTextNode::serialize() {
    std::vector <std::byte> bytes;

    std::string info = std::string("theme") + SERIALIZEABLE_VALUE_DEFINER + "default" + SERIALIZEABLE_VALUE_ENDER +
            "position" + SERIALIZEABLE_VALUE_DEFINER + std::to_string(border.getPosition().x) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(border.getPosition().y) + SERIALIZEABLE_VALUE_ENDER +
            "title" + SERIALIZEABLE_VALUE_DEFINER + title->text.getString() + SERIALIZEABLE_VALUE_ENDER +
            "content" + SERIALIZEABLE_VALUE_DEFINER + content->text.getString() + SERIALIZEABLE_VALUE_ENDER;

    bytes.insert(bytes.end(), (std::byte *) info.c_str(), (std::byte *) info.c_str() + info.length());

    bytes.insert(bytes.end(), (std::byte *) &SERIALIZEABLE_OBJECT_DELIMITER, (std::byte *) SERIALIZEABLE_OBJECT_DELIMITER + 1);

    return bytes;
}
