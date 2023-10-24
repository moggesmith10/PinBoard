//
// Created by hakkerboi on 10/19/23.
//

#ifndef PINBOARD_WARMTEXTNODE_HPP
#define PINBOARD_WARMTEXTNODE_HPP


#include "../../ITextNode.hpp"
#include "WarmLine.hpp"

class WarmTextNode : public ITextNode {
public:
    WarmTextNode(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Font font, int fontSize, sf::Color color);
    void draw(sf::RenderWindow *renderWindow) override;
    void handleEvent(sf::Event event, EventResponse *response) override;
    std::vector<WarmLine> lines;
    void move(sf::Vector2f toMove) override;
    bool deserialize(std::string data) override;
    std::string serialize() override;
void setTitle(std::string title) override;
void setContent(std::string content) override;
private:
    void animate();
    bool finished = false;
    std::vector<WarmLine>::iterator currentLine;
    sf::RectangleShape background;
};


#endif //PINBOARD_WARMTEXTNODE_HPP
