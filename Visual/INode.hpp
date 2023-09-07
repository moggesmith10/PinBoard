//
// Created by hakkerboi on 9/5/23.
//

#ifndef PINBOARD_INODE_HPP
#define PINBOARD_INODE_HPP


#include "IDrawable.hpp"
#include "ITextBox.hpp"

class INode : public IDrawable {

protected:
    ITextBox *title;
    ITextBox *content;
public:
    virtual void draw(sf::RenderWindow *renderWindow) = 0;
    bool selected = false;
    virtual void handleEvents(sf::Event event, EventResponse* response) = 0;
};


#endif //PINBOARD_INODE_HPP
