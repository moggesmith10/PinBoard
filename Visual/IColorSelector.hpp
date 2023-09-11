//
// Created by hakkerboi on 9/11/23.
//

#ifndef PINBOARD_ICOLORSELECTOR_HPP
#define PINBOARD_ICOLORSELECTOR_HPP

#include "IEventHandler.hpp"
#include "IDrawable.hpp"
#include "ISelectable.hpp"

/**
 * Not mandatory for themes to implement.
 */
class IColorSelector : public IDrawable, public IEventHandler, public ISelectable {

};


#endif //PINBOARD_ICOLORSELECTOR_HPP
