//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_CURSORUTILITIES_HPP
#define PINBOARD_CURSORUTILITIES_HPP


#include <SFML/System/Vector2.hpp>

class CursorUtilities {
public:
    static bool isCursorInRect(sf::Vector2f topLeft, sf::Vector2f bottomRight, sf::Vector2f cursorPosition);
    static float distanceToLine(sf::Vector2f lineStart, sf::Vector2f lineEnd, sf::Vector2f point);
};


#endif //PINBOARD_CURSORUTILITIES_HPP
