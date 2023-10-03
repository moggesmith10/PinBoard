//
// Created by hakkerboi on 9/4/23.
//

#include "Globals.hpp"

Globals::Globals() {
    fontUtilites = new FontUtilities();
    textures[0] =  new sf::Texture();
    textures[0]->loadFromFile("Resources/Textures/DefaultImageNode.png");
}

Globals::~Globals() {
    delete fontUtilites;
}
