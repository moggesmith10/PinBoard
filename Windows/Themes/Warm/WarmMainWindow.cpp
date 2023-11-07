//
// Created by hakkerboi on 10/11/23.
//

#include "WarmMainWindow.hpp"
#include "../../../Visual/Themes/Warm/WarmContextMenu.hpp"
#include "../../../Visual/Themes/Warm/WarmTextNode.hpp"

WarmMainWindow::WarmMainWindow(Globals *globals) {
    this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Pinboard");
    this->renderWindow->setFramerateLimit(60);
    this->globals = globals;
    this->contextMenu = new WarmContextMenu(globals);
}

void WarmMainWindow::draw() {
    this->renderWindow->clear(sf::Color(200, 180, 150));
    this->contextMenu->draw(this->renderWindow);
    for(auto &textNode : this->textNodes){
        textNode->draw(this->renderWindow);
    }
    this->renderWindow->display();
}

void WarmMainWindow::handleEvents() {
    sf::Event event;
    while (this->renderWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->renderWindow->close();
        }
        if(event.type == sf::Event::Resized){
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            this->renderWindow->setView(sf::View(visibleArea));
        }

        EventResponse *response = new EventResponse();
        this->contextMenu->handleEvent(event, response);

        if(response->getCreateTextNode()){
            this->textNodes.insert(this->textNodes.end(), new WarmTextNode(sf::Vector2f(200, 200), sf::Vector2f(200,200), "Hello World", *this->globals->fontUtilites->getFont(FontUtilities::NotoSansMedium), 20, sf::Color(255, 255, 255)));
        }
    }
}

WarmMainWindow::~WarmMainWindow() {

}
