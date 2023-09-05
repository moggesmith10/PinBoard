//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultMainWindowContextMenu.hpp"
#include "DefaultNode.hpp"

void DefaultMainWindowContextMenu::draw(sf::RenderWindow* renderWindow) {
    renderWindow->draw(background);
    addNodeButton.draw();
}

DefaultMainWindowContextMenu::DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position, Globals *globals, IMainWindow *mainWindow) {
    this->renderWindow = renderWindow;
    this->background = sf::RectangleShape(sf::Vector2f(200, 400));
    this->background.setFillColor(sf::Color(200, 200, 220));
    this->background.setPosition(position);
    this->globals = globals;
    this->mainWindow = mainWindow;
    this->addNodeButton = DefaultMainWindowContextMenuItem("Add Node", globals, renderWindow, sf::Vector2f(position.x + 10, position.y + 10));
}

DefaultMainWindowContextMenu::~DefaultMainWindowContextMenu() {

}

bool DefaultMainWindowContextMenu::handleEvent(sf::Event event) {

        if(addNodeButton.handleEvent(event)) {
            mainWindow->nodes.insert(mainWindow->nodes.end(),
                                     new DefaultNode(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), globals));
            return true;
        }
    return false;
}
