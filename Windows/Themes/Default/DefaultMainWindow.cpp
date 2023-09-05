//
// Created by hakkerboi on 9/4/23.
//

#include <functional>
#include <future>
#include "DefaultMainWindow.hpp"
#include "../../../Visual/Themes/Default/DefaultMainWindowContextMenu.hpp"

DefaultMainWindow::DefaultMainWindow(Globals *globals) : IMainWindow() {
    this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Pinboard");
    this->renderWindow->setFramerateLimit(60);
    this->globals = globals;
}

void DefaultMainWindow::handleEvents() {
    sf::Event event;
    while (this->renderWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->renderWindow->close();
        }
        if(contextMenu != nullptr)
            if(contextMenu->handleEvent(event)) {
                delete contextMenu;
                contextMenu = nullptr;
            }

        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Right){
                createContextMenu(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            } else if(event.mouseButton.button == sf::Mouse::Left){
                if(contextMenu != nullptr){
                    delete contextMenu;
                    contextMenu = nullptr;
                }
            }
        }
    }
}

void DefaultMainWindow::draw() {
    this->renderWindow->clear(sf::Color::Black);
    if(this->contextMenu != nullptr){
        this->contextMenu->draw(renderWindow);
    }
    for(INode *node : this->nodes){
        node->draw(this->renderWindow);
    }
    this->renderWindow->display();
}

void DefaultMainWindow::createContextMenu(sf::Vector2f position) {
    delete this->contextMenu;

    this->contextMenu = new DefaultMainWindowContextMenu(this->renderWindow, position, globals, this);
}
