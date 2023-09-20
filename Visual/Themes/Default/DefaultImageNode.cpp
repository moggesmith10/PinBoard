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

bool DefaultImageNode::deserialize(std::string info) {
    std::string theme = info.substr(info.find(std::string("theme") + SERIALIZEABLE_VALUE_DEFINER), info.find(SERIALIZEABLE_VALUE_ENDER));
    std::string position = info.substr(info.find(std::string("position") + SERIALIZEABLE_VALUE_DEFINER), info.find(SERIALIZEABLE_VALUE_ENDER));
    std::string type = info.substr(info.find(std::string("type") + SERIALIZEABLE_VALUE_DEFINER), info.find(SERIALIZEABLE_VALUE_ENDER));

    std::string texture = info.substr(info.find_last_of(SERIALIZEABLE_OBJECT_DELIMITER) + 1);

    delete this->texture;
    this->texture = new sf::Texture();
    this->texture->loadFromMemory(reinterpret_cast<const sf::Uint8 *>(texture.c_str()), texture.length());
    sprite = sf::Sprite();
    sprite.setTexture(*this->texture);

    return true;
}

std::string DefaultImageNode::serialize() {

    std::string info = std::string("theme") + SERIALIZEABLE_VALUE_DEFINER+ "default" + SERIALIZEABLE_VALUE_SEPARATOR
            + "position" + SERIALIZEABLE_VALUE_DEFINER + std::to_string(sprite.getPosition().x) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(sprite.getPosition().y) + SERIALIZEABLE_VALUE_SEPARATOR +
            "type" + SERIALIZEABLE_VALUE_DEFINER + "image" + SERIALIZEABLE_VALUE_SEPARATOR;

    sf::Image image = texture->copyToImage();
    const char *texture;
    image.saveToMemory(reinterpret_cast<std::vector<sf::Uint8> &>(texture), "png");
    info.append(texture);

    info += SERIALIZEABLE_OBJECT_DELIMITER;

    return info;
}

DefaultImageNode::DefaultImageNode() {

}
