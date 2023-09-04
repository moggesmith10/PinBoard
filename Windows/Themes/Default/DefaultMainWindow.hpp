//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_DEFAULTMAINWINDOW_HPP
#define PINBOARD_DEFAULTMAINWINDOW_HPP


#include "../../MainWindow.hpp"

class DefaultMainWindow : public MainWindow
{
public:
    DefaultMainWindow();
    void handleEvents() override;
    void draw() override;
};


#endif //PINBOARD_DEFAULTMAINWINDOW_HPP
