//
// Created by hakkerboi on 9/5/23.
//

#include "DefaultNode.hpp"

void DefaultNode::draw(sf::RenderWindow* renderWindow) {
    renderWindow->draw(background);
    renderWindow->draw(text);
}

DefaultNode::DefaultNode(sf::Vector2f position, Globals* globals) {
    background = sf::RectangleShape(sf::Vector2f(400, 400));
    background.setFillColor(sf::Color(160, 150, 150));
    background.setPosition(position);
    text = sf::Text("Default Node", *globals->fontUtilites->getFont(FontUtilities::NotoSansMedium), 20);
    text.setPosition(position.x + 10, position.y + 10);
}