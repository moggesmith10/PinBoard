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
    sprite.setScale(300 / texture->getSize().x, 300 / texture->getSize().y);
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

bool DefaultImageNode::deserialize(std::byte* data) {
    std::string info = (char*) data;
    std::string theme = info.substr(info.find(':'), info.find(';'));
    info = info.substr(info.find(';') + 1);
    std::string position = info.substr(info.find(':'), info.find(';'));
    info = info.substr(info.find(';') + 1);

    std::string x = position.substr(info.find(':'), position.find(','));
    std::string y = position.substr(position.find(',') + 1);

    sprite.setPosition(std::stof(x), std::stof(y));

    std::string texture = info.substr(0, info.find(';'));

    this->texture = (sf::Texture*) std::stoi(texture);

    sprite.setTexture(*this->texture);

    return true;
}

std::byte *DefaultImageNode::serialize() {
    std::vector<std::byte> bytes;

    std::string info = std::string("theme") + SERIALIZEABLE_VALUE_DEFINER+ "default" + SERIALIZEABLE_VALUE_SEPARATOR
            + "position" + SERIALIZEABLE_VALUE_DEFINER + std::to_string(sprite.getPosition().x) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(sprite.getPosition().y) + SERIALIZEABLE_VALUE_SEPARATOR;

    bytes.insert(bytes.end(), (std::byte *) info.c_str(), (std::byte *) info.c_str() + info.length());
    bytes.insert(bytes.end(), (std::byte *) &texture, (std::byte *) &texture + sizeof(texture));

    bytes.insert(bytes.end(), (std::byte *) &SERIALIZEABLE_OBJECT_DELIMITER, (std::byte *) SERIALIZEABLE_OBJECT_DELIMITER + sizeof(SERIALIZEABLE_OBJECT_DELIMITER));


    return bytes.data();
}

DefaultImageNode::DefaultImageNode() {

}
