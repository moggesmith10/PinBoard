//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_INODE_HPP
#define PINBOARD_INODE_HPP


#include "IDrawable.hpp"
#include "ITextBox.hpp"
#include "IEventHandler.hpp"

class INode : public IDrawable, public IEventHandler{

protected:
    ITextBox *title;
    ITextBox *content;
public:
    bool selected = false;
    sf::Vector2f center;
};


#endif //PINBOARD_INODE_HPP
