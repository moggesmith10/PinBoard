//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_ICONTEXTMENU_HPP
#define PINBOARD_ICONTEXTMENU_HPP

#include "../Utilites/Globals.hpp"
#include "IDrawable.hpp"
#include "../Utilites/EventResponse.hpp"
#include "IEventHandler.hpp"

class IContextMenu : public IDrawable, public IEventHandler{
public:
    enum menuContext {
        NODE,
        CONNECTION,
        BOTH,
        NONE
    };

protected:
    Globals *globals;
};

#endif //PINBOARD_ICONTEXTMENU_HPP
