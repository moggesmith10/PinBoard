//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IMAINWINDOW_HPP
#define PINBOARD_IMAINWINDOW_HPP

#include "IWindow.hpp"
#include "../Visual/IContextMeny.hpp"

class IMainWindow : public IWindow {
public:
    IContextMenu *contextMenu = nullptr;
};
#endif //PINBOARD_IMAINWINDOW_HPP
