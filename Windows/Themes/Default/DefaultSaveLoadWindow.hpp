//
// Created by hakkerboi on 9/19/23.
//

#ifndef PINBOARD_DEFAULTSAVELOADWINDOW_HPP
#define PINBOARD_DEFAULTSAVELOADWINDOW_HPP


#include "../../ISaveLoadWindow.hpp"
#include "../../../Visual/Themes/Default/DefaultTextBox.hpp"

class DefaultSaveLoadWindow : public ISaveLoadWindow {
public:
    DefaultSaveLoadWindow(Pinboard* pinboard);

    void handleEvents() override;
    void draw() override;

    DefaultTextBox* saveTextBox;
};


#endif //PINBOARD_DEFAULTSAVELOADWINDOW_HPP
