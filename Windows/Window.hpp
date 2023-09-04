//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_WINDOW_HPP
#define PINBOARD_WINDOW_HPP

#include <thread>
#include "SFML/Graphics.hpp"

class Window{
public:
    sf::RenderWindow *renderWindow;
    virtual void handleEvents() = 0;
    virtual void draw() = 0;

};

#endif //PINBOARD_WINDOW_HPP
