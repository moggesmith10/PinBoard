//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_ITEXTNODE_HPP
#define PINBOARD_ITEXTNODE_HPP


#include "IDrawable.hpp"
#include "ITextBox.hpp"
#include "IEventHandler.hpp"
#include "ISelectable.hpp"
#include "INode.hpp"

class ITextNode :  public INode{

protected:
    ITextBox *title;
    ITextBox *content;

};


#endif //PINBOARD_ITEXTNODE_HPP
