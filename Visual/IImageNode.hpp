//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_IIMAGENODE_HPP
#define PINBOARD_IIMAGENODE_HPP


#include "IDrawable.hpp"
#include "ISelectable.hpp"
#include "IEventHandler.hpp"
#include "INode.hpp"

class IImageNode : public INode {
protected:
    sf::Texture* texture;
};


#endif //PINBOARD_IIMAGENODE_HPP
