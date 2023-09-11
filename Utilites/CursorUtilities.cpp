//
// Created by hakkerboi on 9/4/23.
//

#include "CursorUtilities.hpp"
#include <math.h>

bool CursorUtilities::isCursorInRect(sf::Vector2f position, sf::Vector2f size, sf::Vector2f mousePosition) {
    return mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
           mousePosition.y >= position.y && mousePosition.y <= position.y + size.y;
}

float CursorUtilities::distanceToLine(sf::Vector2f lineStart, sf::Vector2f lineEnd, sf::Vector2f point) {
    float distance = ((lineEnd.x-lineStart.x)*(lineStart.y-point.y)-(lineStart.x-point.x)*(lineEnd.y-lineStart.y))/sqrt(pow(lineEnd.x-lineStart.x,2)+pow(lineEnd.y-lineStart.y,2));
    return distance;
}
