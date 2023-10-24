//
// Created by hakkerboi on 10/19/23.
//

#include "WarmTextNode.hpp"

void WarmTextNode::handleEvent(sf::Event event, EventResponse *response) {

}

void WarmTextNode::draw(sf::RenderWindow *renderWindow) {
    if(!finished)
        animate();
    for(auto line : lines){
        line.draw(renderWindow);
    }

}

void WarmTextNode::animate() {
    if(!currentLine->finished){
        currentLine->iterate();
    } else {
        if(currentLine != --lines.end()){
            currentLine++;
            currentLine->start();
        }
        else{
            finished = true;
        }
    }
}

WarmTextNode::WarmTextNode(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Font font, int fontSize,
                           sf::Color color) {
    lines.insert(lines.end(), WarmLine(position, position + sf::Vector2f(200,0), color, 20));
    lines.insert(lines.end(), WarmLine(position + sf::Vector2f(0,20), position + sf::Vector2f(100,20), color, 20));
    lines.insert(lines.end(), WarmLine(position + sf::Vector2f(100,20), position + sf::Vector2f(120,0), color, 5));
    lines.insert(lines.end(), WarmLine(position + sf::Vector2f(0,0), position + sf::Vector2f(0,size.y), color, 20));

    currentLine = lines.begin();
    currentLine->start();
}

void WarmTextNode::move(sf::Vector2f toMove) {
    for(auto line : lines){
        line.move(toMove);
    }
}

std::string WarmTextNode::serialize() {
    return std::string();
}

bool WarmTextNode::deserialize(std::string data) {
    return false;
}

void WarmTextNode::setTitle(std::string title) {

}

void WarmTextNode::setContent(std::string content) {

}
