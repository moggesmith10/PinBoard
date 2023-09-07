//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultMainWindowContextMenu.hpp"
#include "DefaultNode.hpp"

void DefaultMainWindowContextMenu::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    addNodeButton.draw();
    deleteNodesButton.draw();
}

DefaultMainWindowContextMenu::DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position,
                                                           Globals *globals, IMainWindow *mainWindow) {
    this->renderWindow = renderWindow;
    this->background = sf::RectangleShape(sf::Vector2f(200, 400));
    this->background.setFillColor(sf::Color(200, 200, 220));
    this->background.setPosition(position);
    this->globals = globals;
    this->mainWindow = mainWindow;
    this->addNodeButton = DefaultMainWindowContextMenuItem("Add Node", globals, renderWindow,
                                                           sf::Vector2f(position.x + 10, position.y + 10));
    this->deleteNodesButton = DefaultMainWindowContextMenuItem("Delete Nodes", globals, renderWindow,
                                                               sf::Vector2f(position.x + 10, position.y + 50));
}

DefaultMainWindowContextMenu::~DefaultMainWindowContextMenu() {

}

void DefaultMainWindowContextMenu::handleEvent(sf::Event event, EventResponse *response) {
    EventResponse *addNodeResponse = new EventResponse();
    addNodeButton.handleEvent(event, addNodeResponse);
    if (addNodeResponse->getPress()) {
        mainWindow->nodes.insert(mainWindow->nodes.end(),
                                 new DefaultNode(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), globals));
        response->setDelete(true);
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (!addNodeResponse->getPress()) {
            response->setDelete(true);
        }
    }

    EventResponse *deleteNodesResponse = new EventResponse();
    deleteNodesButton.handleEvent(event, deleteNodesResponse);
    if (deleteNodesResponse->getPress()) {
        response->setDeleteSelectedNodes(true);
        response->setDelete(true);
    }
}
