//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_GLOBALS_HPP
#define PINBOARD_GLOBALS_HPP


#include "FontUtilities.hpp"

class Globals {
public:
    Globals();
    ~Globals();
    sf::Texture* textures[1];
    FontUtilities *fontUtilites;
};


#endif //PINBOARD_GLOBALS_HPP
