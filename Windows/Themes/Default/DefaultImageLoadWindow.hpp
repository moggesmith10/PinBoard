//
// Created by hakkerboi on 10/9/23.
//

#ifndef PINBOARD_DEFAULTIMAGELOADWINDOW_HPP
#define PINBOARD_DEFAULTIMAGELOADWINDOW_HPP


#include "../../IImageLoadWindow.hpp"
#include "../../../Visual/Themes/Default/DefaultTextBox.hpp"
#include "../../../Visual/Themes/Default/DefaultButton.hpp"

class DefaultImageLoadWindow : public IImageLoadWindow {

public:
    DefaultImageLoadWindow(Globals* globals);

    void handleEvents() override;

    void draw() override;
    ~DefaultImageLoadWindow();

private:
    DefaultTextBox *pathTextbox;
    DefaultTextBox *selected = nullptr;
    DefaultButton *loadButton;
    DefaultButton *cancelButton;
};


#endif //PINBOARD_DEFAULTIMAGELOADWINDOW_HPP
