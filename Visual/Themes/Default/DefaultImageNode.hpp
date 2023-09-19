//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_DEFAULTIMAGENODE_HPP
#define PINBOARD_DEFAULTIMAGENODE_HPP


#include "../../IImageNode.hpp"

class DefaultImageNode : public IImageNode {
    sf::Sprite sprite;
    sf::RectangleShape border;
public:
    DefaultImageNode(sf::Texture *texture, sf::Vector2f position);
    void draw(sf::RenderWindow *renderWindow) override;
    void move(sf::Vector2f toMove) override;
    void handleEvent(sf::Event event, EventResponse *response) override;
};


#endif //PINBOARD_DEFAULTIMAGENODE_HPP
