//
// Created by hakkerboi on 9/10/23.
//

#ifndef PINBOARD_ICONNECTION_HPP
#define PINBOARD_ICONNECTION_HPP


#include "IDrawable.hpp"
#include "INode.hpp"

class IConnection : public IDrawable, public IEventHandler {
public:
    INode *node1;
    INode *node2;
    bool containsNode(INode* node) const{
        return node1 == node || node2 == node;
    };
    bool equals(INode* node1, INode* node2) const{
        return (this->node1 == node1 && this->node2 == node2) || (this->node1 == node2 && this->node2 == node1);
    };
};

#endif //PINBOARD_ICONNECTION_HPP
