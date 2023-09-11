//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_DEFAULTNODE_HPP
#define PINBOARD_DEFAULTNODE_HPP


#include <SFML/Graphics.hpp>
#include "../../INode.hpp"
#include "../../../Utilites/Globals.hpp"

class DefaultNode : public INode {
public:
    void draw(sf::RenderWindow *renderWindow) override;

    DefaultNode(sf::Vector2f position, Globals *globals);

    void handleEvent(sf::Event event, EventResponse* response) override;

private:
    sf::RectangleShape background;
    sf::RectangleShape border;
};


#endif //PINBOARD_DEFAULTNODE_HPP
