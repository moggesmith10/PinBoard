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
public:
    virtual void setTitle(std::string title) = 0;
    virtual void setContent(std::string title) = 0;
protected:
    ITextBox *title;
    ITextBox *content;

};


#endif //PINBOARD_ITEXTNODE_HPP
