//
// Created by hakkerboi on 9/4/23.
//

#include <functional>
#include <future>
#include "DefaultMainWindow.hpp"

DefaultMainWindow::DefaultMainWindow() : MainWindow() {
    this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Pinboard");
    this->renderWindow->setFramerateLimit(60);

}

void DefaultMainWindow::handleEvents() {
    sf::Event event;
    while (this->renderWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->renderWindow->close();
        }
    }
}

void DefaultMainWindow::draw() {
    this->renderWindow->clear(sf::Color::Black);
    this->renderWindow->display();
}
