//
// Created by hakkerboi on 10/9/23.
//

#include "DefaultImageLoadWindow.hpp"

void DefaultImageLoadWindow::draw() {
    renderWindow->clear(sf::Color::White);
    pathTextbox->draw(renderWindow);
    loadButton->draw(renderWindow);
    cancelButton->draw(renderWindow);
    renderWindow->display();
}

DefaultImageLoadWindow::DefaultImageLoadWindow(Globals* globals) {
    renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Pinboard");
    renderWindow->setFramerateLimit(60);
    this->globals = globals;
    pathTextbox = new DefaultTextBox(globals, sf::Vector2f(0, 0), "/home/hakkerboi/Pictures/bord.png");
    loadButton = new DefaultButton("Load", globals, renderWindow, sf::Vector2f(0, 50));
    cancelButton = new DefaultButton("Cancel", globals, renderWindow, sf::Vector2f(0, 100));
}

void DefaultImageLoadWindow::handleEvents() {
    sf::Event event;
    while (renderWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            renderWindow->close();
        }
        else if(event.type == sf::Event::Resized){
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            renderWindow->setView(sf::View(visibleArea));
        }
        else{
            EventResponse* response = new EventResponse();
            pathTextbox->handleEvent(event, response);
            if(response->getPress()){
                selected = pathTextbox;
            }

            response->clear();
            loadButton->handleEvent(event, response);
            if(response->getPress()){
                if(pathTextbox->content != std::string("")){
                    this->image = new sf::Image();
                    bool success = this->image->loadFromFile(pathTextbox->content);
                    if(success){
                        renderWindow->close();
                    }
                }
                renderWindow->close();
            }
            else {
                cancelButton->handleEvent(event, response);
                if(response->getPress())
                    renderWindow->close();
            }
        }
    }
}

DefaultImageLoadWindow::~DefaultImageLoadWindow() {
    delete renderWindow;
    delete pathTextbox;
    delete loadButton;
    delete cancelButton;
}
