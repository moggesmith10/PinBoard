//
// Created by hakkerboi on 9/10/23.
//

#ifndef PINBOARD_DEFAULTCONNECTION_HPP
#define PINBOARD_DEFAULTCONNECTION_HPP


#include "../../IConnection.hpp"

class DefaultConnection : public IConnection{
public:
    DefaultConnection(INode *node1, INode *node2);
    void draw(sf::RenderWindow *renderWindow) override;
    void handleEvent(sf::Event event, EventResponse *response) override;
    sf::Vertex line[2];
    sf::Vertex selectedLine[4];
    const int thickness = 0;//Unused
    const int thicknessSelected = 4;
    const int hitbox = 10;
    void changeColor(sf::Color color) override;
    void move(sf::Vector2f toMove) override;
    void move(sf::Vector2f toMove, INode* node) override;
};


#endif //PINBOARD_DEFAULTCONNECTION_HPP
