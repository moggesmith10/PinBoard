//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOW_HPP
#define PINBOARD_DEFAULTMAINWINDOW_HPP


#include "../../IMainWindow.hpp"

class DefaultMainWindow : public IMainWindow {
public:
    DefaultMainWindow(Globals *globals);

    void handleEvents() override;

    void draw() override;

private:
    void createContextMenu(sf::Vector2f position);
};


#endif //PINBOARD_DEFAULTMAINWINDOW_HPP
