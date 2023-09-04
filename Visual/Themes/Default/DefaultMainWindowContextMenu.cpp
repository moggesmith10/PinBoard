//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultMainWindowContextMenu.hpp"

void DefaultMainWindowContextMenu::draw() {
    renderWindow->draw(background);
    addNodeButton.draw();
}

DefaultMainWindowContextMenu::DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position, Globals *globals) {
    this->renderWindow = renderWindow;
    this->background = sf::RectangleShape(sf::Vector2f(200, 400));
    this->background.setFillColor(sf::Color(200, 200, 220));
    this->background.setPosition(position);
    this->globals = globals;
    this->addNodeButton = DefaultMainWindowContextMenuItem("Add Node", globals, renderWindow, sf::Vector2f(position.x + 10, position.y + 10));
}

DefaultMainWindowContextMenu::~DefaultMainWindowContextMenu() {

}

void DefaultMainWindowContextMenu::handleEvent(sf::Event event) {

}
