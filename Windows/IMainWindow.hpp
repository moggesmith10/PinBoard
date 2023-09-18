//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IMAINWINDOW_HPP
#define PINBOARD_IMAINWINDOW_HPP

#include "IWindow.hpp"
#include "../Visual/IContextMenu.hpp"
#include "../Visual/ITextNode.hpp"
#include "../Visual/IConnection.hpp"

class IMainWindow : public IWindow {
public:
    IContextMenu *contextMenu = nullptr;
    ITextBox *textBox = nullptr;
    std::vector<INode *> nodes;
    std::vector<INode *> selectedNodes;
    std::vector<IConnection *> connections;
    std::vector<IConnection *> selectedConnections;
    std::vector<ISelectable*> selectedObjects(){
        std::vector<ISelectable*> selectedObjects;
        for(auto node : selectedNodes){
            selectedObjects.push_back(node);
        }
        for(auto connection : selectedConnections){
            selectedObjects.push_back(reinterpret_cast<ISelectable *>(connection));
        }
        return selectedObjects;
    };
};
#endif //PINBOARD_IMAINWINDOW_HPP
