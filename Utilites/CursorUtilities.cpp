//
// Created by hakkerboi on 9/4/23.
//

#include "CursorUtilities.hpp"

bool CursorUtilities::isCursorInRect(sf::Vector2f position, sf::Vector2f size, sf::Vector2f mousePosition) {
    return mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
           mousePosition.y >= position.y && mousePosition.y <= position.y + size.y;
}