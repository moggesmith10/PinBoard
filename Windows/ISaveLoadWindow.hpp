//
// Created by hakkerboi on 9/19/23.
//

#ifndef PINBOARD_ISAVELOADWINDOW_HPP
#define PINBOARD_ISAVELOADWINDOW_HPP


#include "IWindow.hpp"
#include "../Utilites/Pinboard.hpp"

class ISaveLoadWindow : public IWindow{
protected:
    Pinboard* pinboard;
};


#endif //PINBOARD_ISAVELOADWINDOW_HPP
