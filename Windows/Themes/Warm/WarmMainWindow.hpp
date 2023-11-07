//
// Created by hakkerboi on 10/11/23.
//

#ifndef PINBOARD_WARMMAINWINDOW_HPP
#define PINBOARD_WARMMAINWINDOW_HPP


#include "../../IMainWindow.hpp"

class WarmMainWindow : public IMainWindow {
public:
    WarmMainWindow(Globals* globals);

    void handleEvents() override;

    void draw() override;

    ~WarmMainWindow();
private:
    IContextMenu *contextMenu;
};


#endif //PINBOARD_WARMMAINWINDOW_HPP
