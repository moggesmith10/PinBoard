//
// Created by hakkerboi on 10/19/23.
//

#include "WarmLine.hpp"

void WarmLine::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(line, 2, sf::Lines);
}

void WarmLine::iterate() {
    if(!finished && started){
        if (frame < frames) {
            sf::Vector2f diff = endPoint - startPoint;
            float x = diff.x / frames * frame;
            float y = diff.y / frames * frame;
            line[1].position = line[0].position + sf::Vector2f(x, y);
        } else {
            finished = true;
        }
    }
    frame++;
}

WarmLine::WarmLine(sf::Vector2f startPoint, sf::Vector2f endPoint, sf::Color color, int frames) {
    this->frames = frames;
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    line[0].position = startPoint;
    line[1].position = startPoint;
    line[0].color = color;
    line[1].color = color;
}

void WarmLine::move(sf::Vector2f toMove) {
    line[0].position += toMove;
    line[1].position += toMove;
}

void WarmLine::start() {
    started = true;
}
