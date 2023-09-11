//
// Created by hakkerboi on 9/4/23.
//

#include "Globals.hpp"

Globals::Globals() {
    fontUtilites = new FontUtilities();
}

Globals::~Globals() {
    delete fontUtilites;
}
