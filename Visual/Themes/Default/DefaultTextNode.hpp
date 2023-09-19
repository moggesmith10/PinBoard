//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_DEFAULTTEXTNODE_HPP
#define PINBOARD_DEFAULTTEXTNODE_HPP


#include <SFML/Graphics.hpp>
#include "../../ITextNode.hpp"
#include "../../../Utilites/Globals.hpp"

class DefaultTextNode : public ITextNode {
public:
    void draw(sf::RenderWindow *renderWindow) override;

    DefaultTextNode(sf::Vector2f position, Globals *globals);

    void handleEvent(sf::Event event, EventResponse* response) override;

    void move(sf::Vector2f toMove) override;

    bool deserialize(std::byte* data) override;
    std::byte * serialize() override;
private:
    sf::RectangleShape background;
    sf::RectangleShape border;
};


#endif //PINBOARD_DEFAULTTEXTNODE_HPP
