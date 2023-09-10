//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IMAINWINDOW_HPP
#define PINBOARD_IMAINWINDOW_HPP

#include "IWindow.hpp"
#include "../Visual/IContextMeny.hpp"
#include "../Visual/INode.hpp"
#include "../Visual/IConnection.hpp"

class IMainWindow : public IWindow {
public:
    IContextMenu *contextMenu = nullptr;
    ITextBox *textBox = nullptr;
    std::vector<INode *> nodes;
    std::vector<INode *> selectedNodes;
    std::vector<IConnection *> connections;
};

#endif //PINBOARD_IMAINWINDOW_HPP
