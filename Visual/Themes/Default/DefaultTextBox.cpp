//
// Created by hakkerboi on 9/6/23.
//

#include "DefaultTextBox.hpp"

DefaultTextBox::DefaultTextBox(Globals *globals, sf::Vector2f position) {
    text.setFont(*globals->fontUtilites->getFont(FontUtilities::NotoSansMedium));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(position);
    content = "Test";
    text.setString(content);
}

void DefaultTextBox::draw(sf::RenderWindow *renderWindow) {
    if(isFocused){
        text.setFillColor(sf::Color::Red);
    }
    else{
        text.setFillColor(sf::Color::Black);
    }
    renderWindow->draw(text);
}

void DefaultTextBox::handleEvent(sf::Event event, EventResponse *response) {
    if (event.type == sf::Event::TextEntered && isFocused) {
        if (event.text.unicode < 128) {
            if (event.text.unicode == 8) {
                if (!content.empty()) {
                    content.pop_back();
                }
            } else {
                content += static_cast<char>(event.text.unicode);
            }
            text.setString(content);
        }
        if(event.text.unicode == 13){
            isFocused = false;
            response->setDeleteSelectedNodes(true);
        }
    }
    else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
            isFocused = true;
            response->setPress(true);
        }
        else{
            isFocused = false;
        }
    }
}

void DefaultTextBox::move(sf::Vector2f toMove) {
    text.setPosition(text.getPosition() + toMove);
}
