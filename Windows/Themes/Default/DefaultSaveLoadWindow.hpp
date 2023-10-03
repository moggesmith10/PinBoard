//
// Created by hakkerboi on 9/19/23.
//

#ifndef PINBOARD_DEFAULTSAVELOADWINDOW_HPP
#define PINBOARD_DEFAULTSAVELOADWINDOW_HPP


#include "../../ISaveLoadWindow.hpp"
#include "../../../Visual/Themes/Default/DefaultTextBox.hpp"
#include "../../../Visual/Themes/Default/DefaultButton.hpp"

class DefaultSaveLoadWindow : public ISaveLoadWindow {
public:
    DefaultSaveLoadWindow(Pinboard* pinboard, Globals* globals);

    bool closeMe = false;

    void handleEvents() override;
    void draw() override;
    Globals *globals;

    DefaultTextBox* saveTextBox;
    DefaultButton* saveButton;
    DefaultButton* loadButton;
};


#endif //PINBOARD_DEFAULTSAVELOADWINDOW_HPP
