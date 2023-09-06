//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IWINDOW_HPP
#define PINBOARD_IWINDOW_HPP

#include <thread>
#include "SFML/Graphics.hpp"
#include "../Utilites/Globals.hpp"

class IWindow {
public:
    sf::RenderWindow *renderWindow;

    virtual void handleEvents() = 0;

    virtual void draw() = 0;

    Globals *globals;
};

#endif //PINBOARD_IWINDOW_HPP
