//
// Created by hakkerboi on 10/24/23.
//

#ifndef PINBOARD_IANIMATEABLERECTANGLECOLOR_HPP
#define PINBOARD_IANIMATEABLERECTANGLECOLOR_HPP


#include "IAnimateable.hpp"

class IAnimateableRectangleColor : public IAnimateable {
public:
    sf::Color startColor;
    sf::Color endColor;
    int frames;
    bool finished = false;
    virtual void start() = 0;
protected:
    int currentFrame = 0;
};


#endif //PINBOARD_IANIMATEABLERECTANGLECOLOR_HPP
