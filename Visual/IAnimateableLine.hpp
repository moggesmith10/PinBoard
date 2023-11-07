//
// Created by hakkerboi on 10/19/23.
//

#ifndef PINBOARD_IANIMATEABLELINE_HPP
#define PINBOARD_IANIMATEABLELINE_HPP


#include <SFML/System/Vector2.hpp>
#include "IAnimateable.hpp"

class IAnimateableLine : public IAnimateable {
protected:
    sf::Vector2f startPoint;
    sf::Vector2f endPoint;

};


#endif //PINBOARD_IANIMATEABLELINE_HPP
