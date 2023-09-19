//
// Created by hakkerboi on 9/19/23.
//

#include "DefaultSaveLoadWindow.hpp"

DefaultSaveLoadWindow::DefaultSaveLoadWindow(Pinboard *pinboard) {
    this->pinboard = pinboard;
    this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Save / Load");
}

void DefaultSaveLoadWindow::draw() {
}

void DefaultSaveLoadWindow::handleEvents() {

}
