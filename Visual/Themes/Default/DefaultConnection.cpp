//
// Created by hakkerboi on 9/10/23.
//

#include "DefaultConnection.hpp"
#include "../../../Utilites/CursorUtilities.hpp"
#include "../../../Utilites/StringUtils.hpp"

DefaultConnection::DefaultConnection(INode *node1, INode *node2) {
    this->node1 = node1;
    this->node2 = node2;
    line[0] = sf::Vertex(sf::Vector2f(node1->center.x,
                                      node1->center.y));
    line[1] = sf::Vertex(sf::Vector2f(node2->center.x ,
                                      node2->center.y));

    selectedLine[0] = sf::Vertex(sf::Vector2f(node1->center.x - thicknessSelected,node1->center.y - thicknessSelected));
    selectedLine[1] = sf::Vertex(sf::Vector2f(node1->center.x + thicknessSelected, node1->center.y + thicknessSelected));
    selectedLine[2] = sf::Vertex(sf::Vector2f(node2->center.x - thicknessSelected, node2->center.y - thicknessSelected));
    selectedLine[3] = sf::Vertex(sf::Vector2f(node2->center.x + thicknessSelected, node2->center.y + thicknessSelected));
    this->id = RandomNumberGenerator::getRandomNumber();
}

void DefaultConnection::draw(sf::RenderWindow *renderWindow) {
    if(selected)
        renderWindow->draw(selectedLine, 4, sf::TriangleStrip);
    else
        renderWindow->draw(line, 2, sf::Lines);
}

void DefaultConnection::handleEvent(sf::Event event, EventResponse *response) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        float dist = CursorUtilities::distanceToLine(line[0].position, line[1].position, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        if(dist < hitbox && dist > -hitbox){
            response->setPress(true);
            response->setConnectTo(this);
        }
    }
}

void DefaultConnection::changeColor(sf::Color color) {
    line[0].color = color;
    line[1].color = color;
    selectedLine[0].color = color;
    selectedLine[1].color = color;
    selectedLine[2].color = color;
    selectedLine[3].color = color;
}

void DefaultConnection::move(sf::Vector2f toMove) {
    line[0].position += toMove;
    line[1].position += toMove;
    selectedLine[0].position += toMove;
    selectedLine[1].position += toMove;
    selectedLine[2].position += toMove;
    selectedLine[3].position += toMove;
}

void DefaultConnection::move(sf::Vector2f toMove, INode *node) {
    if(node == node1){
        line[0].position += toMove;
        selectedLine[0].position += toMove;
        selectedLine[1].position += toMove;
    }
    else if(node == node2){
        line[1].position += toMove;
        selectedLine[2].position += toMove;
        selectedLine[3].position += toMove;
    }
}

bool DefaultConnection::deserialize(std::string data) {
    std::vector<std::string> values = StringUtils::findMultiParameter(data, "colour");
    this->changeColor(sf::Color(stoi(values[0]), stoi(values[1]), stoi(values[2]), stoi(values[3])));

    return true;
}

std::string DefaultConnection::serialize() {
    std::string toReturn;
    toReturn += std::string("type") + SERIALIZEABLE_VALUE_DEFINER + std::string("connection") + SERIALIZEABLE_VALUE_ENDER;
    toReturn += std::string("theme") + SERIALIZEABLE_VALUE_DEFINER + std::string("default") + SERIALIZEABLE_VALUE_ENDER;
    toReturn += std::string("colour") + SERIALIZEABLE_VALUE_DEFINER + std::to_string(line[0].color.r) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(line[0].color.g) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(line[0].color.b) + SERIALIZEABLE_MULTIVALUE_SEPARATOR + std::to_string(line[0].color.a) + SERIALIZEABLE_VALUE_ENDER;
    toReturn += std::string("node1") + SERIALIZEABLE_VALUE_DEFINER + std::to_string(node1->id) + SERIALIZEABLE_VALUE_ENDER;
    toReturn += std::string("node2") + SERIALIZEABLE_VALUE_DEFINER + std::to_string(node2->id) + SERIALIZEABLE_VALUE_ENDER;
    toReturn += SERIALIZEABLE_OBJECT_DELIMITER;
    return toReturn;
}
