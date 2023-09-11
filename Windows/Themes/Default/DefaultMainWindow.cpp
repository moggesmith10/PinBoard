//
// Created by hakkerboi on 9/4/23.
//

#include <functional>
#include "DefaultMainWindow.hpp"


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
            if(response->getChangeConnectionColor()){
                selectedConnectionColor = response->connectionColor;
                for(IConnection* connection: selectedConnections){
                    connection->changeColor(response->connectionColor);
                }
            }
            if (response->getDelete()) {
                delete contextMenu;
                contextMenu = nullptr;
            }
        }
        if(response->getDeleteSelectedNodes()){
            for(INode* node: selectedNodes){
                deleteConnectionsToNode(node);
                delete node;
                nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
            }
            selectedNodes.clear();
        }
        if(response->getDeleteSelectedConnections()){
            for(IConnection* connection: selectedConnections){
                delete connection;
                connections.erase(std::remove(connections.begin(), connections.end(), connection), connections.end());
            }
            selectedConnections.clear();
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
                    for(IConnection* selectedConnection: this->connections){
                        selectedConnection->selected = false;
                    }
                    selectedNodes.clear();
                    selectedConnections.clear();
                }
            }
        }

        for(IConnection* connection: connections){
            response->clear();
            connection->handleEvent(event, response);
            if(response->getPress()){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
                    selectedConnections.push_back(connection);
                    connection->selected = true;
                }
                else{
                    for(INode *selectedNode: this->selectedNodes){
                        selectedNode->selected = false;
                    }
                    selectedNodes.clear();
                    for(IConnection* selectedConnection: this->selectedConnections){
                        selectedConnection->selected = false;
                    }
                    selectedConnections.clear();
                    selectedConnections.push_back(connection);
                    connection->selected = true;
                }
            }
        }

        for(INode* node: this->nodes){
            response->clear();
            node->handleEvent(event, response);
            if(response->getSelectTextBox()) {
                if (this->textBox != nullptr) {
                    this->textBox->isFocused = false;
                }
                this->textBox = static_cast<ITextBox *>(response->getSelectedObject());
            }
            if(response->getPress()){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
                    selectedNodes.push_back(node);
                    node->selected = true;
                }
                else{
                    for(IConnection* selectedConnection: this->selectedConnections){
                        selectedConnection->selected = false;
                    }
                    selectedConnections.clear();
                    for(INode* selectedNode: this->selectedNodes){
                        selectedNode->selected = false;
                    }
                    selectedNodes.clear();
                    selectedNodes.push_back(node);
                    node->selected = true;
                }
            }
            if(response->getConnectTo()){
                if(selectedNodes.size() == 1 && selectedNodes[0] != node){
                    if(isConnectionUnique(selectedNodes[0], node)) {
                        DefaultConnection * connection = new DefaultConnection(selectedNodes[0], node);
                        connections.push_back(connection);
                        connection->changeColor(selectedConnectionColor);
                    }
                }
            }
        }

        delete response;
    }
}

void DefaultMainWindow::draw() {
    this->renderWindow->clear(sf::Color::Black);
    for (IConnection *connection: this->connections) {
        connection->draw(this->renderWindow);
    }
    for (INode *node: this->nodes) {
        node->draw(this->renderWindow);
    }
    if (this->contextMenu != nullptr) {
        this->contextMenu->draw(renderWindow);
    }
    this->renderWindow->display();
}

void DefaultMainWindow::createContextMenu(sf::Vector2f position) {
    delete this->contextMenu;

    u_char context = IContextMenu::NONE;

    if(!selectedNodes.empty()){
        context = IContextMenu::NODE;
    }
    if(!selectedConnections.empty()){
        if(context == IContextMenu::NODE){
            context = IContextMenu::BOTH;
        }
        else{
            context = IContextMenu::CONNECTION;
        }
    }

    this->contextMenu = new DefaultMainWindowContextMenu(this->renderWindow, position, globals, this, context, selectedConnectionColor);
}

void DefaultMainWindow::deleteConnectionsToNode(INode *node) {
    for(IConnection* connection: connections){
        if(connection->containsNode(node)){
            delete connection;
            connections.erase(std::remove(connections.begin(), connections.end(), connection), connections.end());
            deleteConnectionsToNode(node);
            break;
        }
    }
}

bool DefaultMainWindow::isConnectionUnique(INode *node1, INode *node2) {
    for(IConnection* connection: connections){
        if(connection->equals(node1, node2)){
            return false;
        }
    }
    return true;
}
