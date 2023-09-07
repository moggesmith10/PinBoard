//
// Created by hakkerboi on 9/4/23.
//

#include <functional>
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
        EventResponse *response = new EventResponse();
        if (contextMenu != nullptr) {
            contextMenu->handleEvent(event, response);
            if (response->getDelete()) {
                delete contextMenu;
                contextMenu = nullptr;
            }
        }
        if(response->getDeleteSelectedNodes()){
            for(INode* node: selectedNodes){
                delete node;
                nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
            }
            selectedNodes.clear();
        }
        response->clear();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                createContextMenu(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
            else {
                if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                      sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {
                    for (INode *selectedNode: this->nodes) {
                        selectedNode->selected = false;
                    }
                    selectedNodes.clear();
                }
            }
        }

        response->clear();

        for(INode* node: this->nodes){
            node->handleEvents(event, response);
            if(response->getSelectedTextBox() != nullptr) {
                if (this->textBox != nullptr) {
                    this->textBox->isFocused = false;
                }
                this->textBox = static_cast<ITextBox *>(response->getSelectedTextBox());
            }
            if(response->getPress()){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
                    selectedNodes.push_back(node);
                    node->selected = true;
                }
                else{

                    selectedNodes.push_back(node);
                    node->selected = true;
                }
            }
        }

        delete response;
    }
}

void DefaultMainWindow::draw() {
    this->renderWindow->clear(sf::Color::Black);
    if (this->contextMenu != nullptr) {
        this->contextMenu->draw(renderWindow);
    }
    for (INode *node: this->nodes) {
        node->draw(this->renderWindow);
    }
    this->renderWindow->display();
}

void DefaultMainWindow::createContextMenu(sf::Vector2f position) {
    delete this->contextMenu;

    this->contextMenu = new DefaultMainWindowContextMenu(this->renderWindow, position, globals, this);
}
