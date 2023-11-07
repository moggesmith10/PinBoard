//
// Created by hakkerboi on 10/9/23.
//

#ifndef PINBOARD_IIMAGELOADWINDOW_HPP
#define PINBOARD_IIMAGELOADWINDOW_HPP


#include "IWindow.hpp"

class IImageLoadWindow : public IWindow {
public:
    sf::Image* image = nullptr;
};


#endif //PINBOARD_IIMAGELOADWINDOW_HPP
