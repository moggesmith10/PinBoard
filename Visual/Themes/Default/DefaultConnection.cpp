//
// Created by hakkerboi on 9/10/23.
//

#include "DefaultConnection.hpp"

DefaultConnection::DefaultConnection(INode *node1, INode *node2) {
    this->node1 = node1;
    this->node2 = node2;
    line[0] = sf::Vertex(sf::Vector2f(node1->center.x,
                                      node1->center.y));
    line[1] = sf::Vertex(sf::Vector2f(node2->center.x ,
                                      node2->center.y));
}

void DefaultConnection::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(line, 2, sf::Lines);
}

void DefaultConnection::handleEvent(sf::Event event, EventResponse *response) {

}
