//
// Created by hakkerboi on 10/16/23.
//

#include "WarmButton.hpp"

WarmButton::WarmButton(Globals *globals, sf::Vector2f position, sf::Vector2f size, std::string text) {
    this->globals = globals;
    this->background = sf::RectangleShape(size);
    this->background.setPosition(position);
    this->background.setFillColor(sf::Color(100, 80, 60));
    this->text = sf::Text(text, *globals->fontUtilites->getFont(FontUtilities::NotoSansMedium), 20);
    this->text.setPosition(position);
    this->text.setFillColor(sf::Color(255, 255, 255));
}

void WarmButton::handleEvent(sf::Event event, EventResponse *response) {
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            if(isHovered(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
                response->setPress(true);
            }
        }
    }
    else if(event.type == sf::Event::MouseMoved){
        if(isHovered(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))){
            background.setFillColor(sf::Color(120, 100, 80));
        }
        else{
            background.setFillColor(sf::Color(100, 80, 60));
        }
    }
}

void WarmButton::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    renderWindow->draw(text);
}

void WarmButton::move(sf::Vector2f toMove) {

}

bool WarmButton::isHovered(sf::Vector2f position) {
    return background.getGlobalBounds().contains(position);
}

WarmButton::~WarmButton() {

}
