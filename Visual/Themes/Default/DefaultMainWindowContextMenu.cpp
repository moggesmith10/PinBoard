//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultMainWindowContextMenu.hpp"
#include "DefaultTextNode.hpp"
#include "DefaultImageNode.hpp"

void DefaultMainWindowContextMenu::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    addTextNodeButton.draw(renderWindow);
    addImageNodeButton.draw(renderWindow);
    if(context == BOTH || context == NODE)
        deleteNodesButton.draw(renderWindow);
    if(context == BOTH || context == CONNECTION)
        deleteConnectionsButton.draw(renderWindow);
    if(context == BOTH)
        deleteBothButton.draw(renderWindow);

saveLoadButton.draw(renderWindow);

    redColorSelector.draw(renderWindow);
    greenColorSelector.draw(renderWindow);
    blueColorSelector.draw(renderWindow);
    yellowColorSelector.draw(renderWindow);
    orangeColorSelector.draw(renderWindow);
    purpleColorSelector.draw(renderWindow);
}

DefaultMainWindowContextMenu::DefaultMainWindowContextMenu(sf::RenderWindow *renderWindow, sf::Vector2f position,
                                                           Globals *globals, IMainWindow *mainWindow, u_char context, sf::Color connectionColor) {
    this->renderWindow = renderWindow;
    this->background = sf::RectangleShape(sf::Vector2f(250, 400));
    this->background.setFillColor(sf::Color(200, 200, 220));
    this->background.setPosition(position);
    this->globals = globals;
    this->mainWindow = mainWindow;
    int y = 50;
    this->addTextNodeButton = DefaultButton("Add Node", globals, renderWindow,
                                            sf::Vector2f(position.x + 10, position.y + (y)));
    this->addImageNodeButton = DefaultButton("Add Image", globals, renderWindow,
                                             sf::Vector2f(position.x + 10, position.y + (y += 50)));

    if(context == BOTH || context == NODE) {
        this->deleteNodesButton = DefaultButton("Delete Nodes", globals, renderWindow,
                                                sf::Vector2f(position.x + 10, position.y + (y += 50)));
    }
    if(context == BOTH || context == CONNECTION)
        this->deleteConnectionsButton = DefaultButton("Delete Connections", globals, renderWindow,
                                                      sf::Vector2f(position.x + 10, position.y + (y += 50)));
    if(context == BOTH)
        this->deleteBothButton = DefaultButton("Delete Both", globals, renderWindow,
                                               sf::Vector2f(position.x + 10, position.y + (y += 50)));

    this->saveLoadButton = DefaultButton("Save/Load", globals, renderWindow,
                                         sf::Vector2f(position.x + 10, position.y + (y += 50)));

    this->redColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 10, position.y + 10), sf::Color::Red, connectionColor == sf::Color::Red);
    this->blueColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 50, position.y + 10), sf::Color::Blue, connectionColor == sf::Color::Blue);
    this->greenColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 90, position.y + 10), sf::Color::Green, connectionColor == sf::Color::Green);
    this->yellowColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 130, position.y + 10), sf::Color::Yellow, connectionColor == sf::Color::Yellow);
    this->orangeColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 170, position.y + 10), sf::Color(255, 165, 0), connectionColor == sf::Color(255, 165, 0));
    this->purpleColorSelector = DefaultColorSelector(sf::Vector2f(position.x + 210, position.y + 10), sf::Color::Magenta, connectionColor == sf::Color::Magenta);

    this->context = context;
}

DefaultMainWindowContextMenu::~DefaultMainWindowContextMenu() {

}

void DefaultMainWindowContextMenu::handleEvent(sf::Event event, EventResponse *response) {
    EventResponse *addNodeResponse = new EventResponse();
    addTextNodeButton.handleEvent(event, addNodeResponse);
    if (addNodeResponse->getPress()) {
        mainWindow->textNodes.insert(mainWindow->textNodes.end(),
                                 new DefaultTextNode(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), globals));
        response->setDelete(true);
    }
    addNodeResponse->clear();
    addImageNodeButton.handleEvent(event, addNodeResponse);
    if (addNodeResponse->getPress()) {
        mainWindow->imageNodes.insert(mainWindow->imageNodes.end(),
                                 new DefaultImageNode(globals->textures[0], sf::Vector2f(event.mouseButton.x, event.mouseButton.y)));
        response->setDelete(true);
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (!addNodeResponse->getPress()) {
            response->setDelete(true);
        }
    }

    delete addNodeResponse;

    if(context == BOTH || context == NODE) {
        EventResponse *deleteNodesResponse = new EventResponse();
        deleteNodesButton.handleEvent(event, deleteNodesResponse);
        if (deleteNodesResponse->getPress()) {
            response->setDeleteSelectedNodes(true);
            response->setDelete(true);
        }
        delete deleteNodesResponse;
    }
    if(context == BOTH || context == CONNECTION) {
        EventResponse *deleteConnectionsResponse = new EventResponse();
        deleteConnectionsButton.handleEvent(event, deleteConnectionsResponse);
        if (deleteConnectionsResponse->getPress()) {
            response->setDeleteSelectedConnections(true);
            response->setDelete(true);
        }
        delete deleteConnectionsResponse;
    }
    if(context == BOTH) {
        EventResponse *deleteBothResponse = new EventResponse();
        deleteBothButton.handleEvent(event, deleteBothResponse);
        if (deleteBothResponse->getPress()) {
            response->setDeleteSelectedNodes(true);
            response->setDeleteSelectedConnections(true);
            response->setDelete(true);
        }
        delete deleteBothResponse;
    }

    EventResponse *saveLoadResponse = new EventResponse();
    saveLoadButton.handleEvent(event, saveLoadResponse);
    if(saveLoadResponse->getPress()){
        response->setOpenSaveLoadWindow(true);
        response->setDelete(true);
    }
    delete saveLoadResponse;

    EventResponse *ColorSelectorResponse = new EventResponse();
    redColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color::Red);
    }
    ColorSelectorResponse->clear();
    blueColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color::Blue);
    }
    ColorSelectorResponse->clear();
    greenColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color::Green);
    }
    ColorSelectorResponse->clear();
    yellowColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color::Yellow);
    }
    ColorSelectorResponse->clear();
    orangeColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color(255, 165, 0));
    }
    ColorSelectorResponse->clear();
    purpleColorSelector.handleEvent(event, ColorSelectorResponse);
    if(ColorSelectorResponse->getPress()){
        response->setChangeConnectionColor(sf::Color::Magenta);
    }
    ColorSelectorResponse->clear();
    delete ColorSelectorResponse;

}

void DefaultMainWindowContextMenu::move(sf::Vector2f toMove) {
    redColorSelector.move(toMove);
    greenColorSelector.move(toMove);
    blueColorSelector.move(toMove);
    yellowColorSelector.move(toMove);
    orangeColorSelector.move(toMove);
    purpleColorSelector.move(toMove);
    background.setPosition(background.getPosition() + toMove);
    addTextNodeButton.move(toMove);
    if(context == BOTH || context == NODE)
        deleteNodesButton.move(toMove);
    if(context == BOTH || context == CONNECTION)
        deleteConnectionsButton.move(toMove);
    if(context == BOTH)
        deleteBothButton.move(toMove);

}
