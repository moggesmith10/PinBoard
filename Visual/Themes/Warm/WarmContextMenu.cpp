//
// Created by hakkerboi on 10/11/23.
//

#include "WarmContextMenu.hpp"

void WarmContextMenu::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    this->createTextNodeButton->draw(renderWindow);
}

WarmContextMenu::WarmContextMenu(Globals *globals) {
    this->globals = globals;
    this->background = sf::RectangleShape(sf::Vector2f(50000, 25));
    this->background.setFillColor(sf::Color(20, 8, 15));
    this->createTextNodeButton = new WarmButton(globals, sf::Vector2f(0, 0), sf::Vector2f(190, 25), "Create Text Node");
}

void WarmContextMenu::handleEvent(sf::Event event, EventResponse *response) {
    EventResponse* buttonResponse = new EventResponse();
    this->createTextNodeButton->handleEvent(event, buttonResponse);
    if (buttonResponse->getPress()){
        response->setCreateTextNode(true);
    }
}

void WarmContextMenu::move(sf::Vector2f toMove) {
    //Do nothing
}

WarmContextMenu::~WarmContextMenu() {

}
