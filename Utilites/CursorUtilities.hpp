//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_CURSORUTILITIES_HPP
#define PINBOARD_CURSORUTILITIES_HPP


#include <SFML/System/Vector2.hpp>

class CursorUtilities {
    static bool isCursorInRect(sf::Vector2f topLeft, sf::Vector2f bottomRight, sf::Vector2f cursorPosition);
};


#endif //PINBOARD_CURSORUTILITIES_HPP
