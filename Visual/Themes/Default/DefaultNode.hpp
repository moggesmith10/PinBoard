//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_DEFAULTNODE_HPP
#define PINBOARD_DEFAULTNODE_HPP


#include <SFML/Graphics.hpp>
#include "../../INode.hpp"
#include "../../../Utilites/Globals.hpp"

class DefaultNode : public INode{
    public:
    void draw(sf::RenderWindow* renderWindow) override;
    DefaultNode(sf::Vector2f position, Globals* globals);
private:
    sf::RectangleShape background;
    sf::Text text;
};


#endif //PINBOARD_DEFAULTNODE_HPP
