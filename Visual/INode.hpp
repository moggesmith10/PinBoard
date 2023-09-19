//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_INODE_HPP
#define PINBOARD_INODE_HPP


#include "IDrawable.hpp"
#include "IEventHandler.hpp"
#include "ISelectable.hpp"
#include "../Utilites/Serializeable.hpp"

class INode : public IDrawable, public IEventHandler, public ISelectable, public Serializeable {
public:
    sf::Vector2f center;
};


#endif //PINBOARD_INODE_HPP
