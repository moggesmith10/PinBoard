//
// Created by hakkerboi on 10/19/23.
//

#ifndef PINBOARD_WARMLINE_HPP
#define PINBOARD_WARMLINE_HPP


#include "../../IAnimateableLine.hpp"
#include "../../../Utilites/EventResponse.hpp"

class WarmLine : public IAnimateableLine {
public:
    WarmLine(sf::Vector2f startPoint, sf::Vector2f endPoint, sf::Color color, int frames);
    sf::Vertex line[2];
    void draw(sf::RenderWindow *renderWindow) override;
    void move(sf::Vector2f toMove) override;
    void iterate() override;
    void start() override;
};


#endif //PINBOARD_WARMLINE_HPP
