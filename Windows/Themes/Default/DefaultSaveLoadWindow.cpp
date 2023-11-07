//
// Created by hakkerboi on 9/19/23.
//

#include "DefaultSaveLoadWindow.hpp"

DefaultSaveLoadWindow::DefaultSaveLoadWindow(Pinboard *pinboard, Globals *globals) {
    this->pinboard = pinboard;
    this->renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Save / Load");

    saveTextBox = new DefaultTextBox(globals, sf::Vector2f(0, 0), "/tmp/pinboard.pbrd");
    saveButton = new DefaultButton("Save", globals, renderWindow, sf::Vector2f(0, 100));
    loadButton = new DefaultButton("Load", globals, renderWindow, sf::Vector2f(0, 150));
}

void DefaultSaveLoadWindow::draw() {
    renderWindow->clear(sf::Color::White);
    saveTextBox->draw(renderWindow);
    saveButton->draw(renderWindow);
    loadButton->draw(renderWindow);
    renderWindow->display();
}

void DefaultSaveLoadWindow::handleEvents() {

    sf::Event event;
    renderWindow->pollEvent(event);
    if(event.type == sf::Event::Closed){
        closeMe = true;
    }

    EventResponse * response = new EventResponse();

    saveTextBox->handleEvent(event, response);

    if(response->getPress()){
        saveTextBox->isFocused = true;
    }

    response->clear();

    saveButton->handleEvent(event, response);
    if(response->getPress()){
        pinboard->writeToDisk(saveTextBox->content);
    }

    response->clear();

    loadButton->handleEvent(event, response);

    if(response->getPress()){
        pinboard->loadFromDisk(saveTextBox->content);
    }
}
