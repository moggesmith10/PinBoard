//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultButton.hpp"
#include "../../../Utilites/CursorUtilities.hpp"

DefaultButton::DefaultButton(
        std::string text, Globals *globals, sf::RenderWindow *renderWindow, sf::Vector2f position) {
    background = sf::RectangleShape(sf::Vector2f(230, 40));
    background.setPosition(position);
    this->renderWindow = renderWindow;
    this->globals = globals;
    this->text = sf::Text(text, *globals->fontUtilites->getFont(FontUtilities::NotoSansMedium), 20);
    this->text.setPosition(position.x + 10, position.y + 10);
    this->text.setFillColor(sf::Color::Black);
}


bool DefaultButton::isHovered(sf::Vector2f position) {
    return background.getGlobalBounds().contains(position);
}

void DefaultButton::handleEvent(sf::Event event, EventResponse *response) {

    bool hovered;
    if (event.type == sf::Event::MouseMoved) {
        hovered = isHovered(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));

        if (hovered) {
            background.setFillColor(sf::Color(180, 180, 200));
        } else {
            background.setFillColor(sf::Color(255, 255, 255));
        }
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        hovered = isHovered(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        if (hovered) {
            background.setFillColor(sf::Color(150, 150, 170));
            response->setPress(true);
        }
    }
}

void DefaultButton::move(sf::Vector2f toMove) {
    background.setPosition(background.getPosition() + toMove);
    text.setPosition(text.getPosition() + toMove);
}

void DefaultButton::draw(sf::RenderWindow *renderWindow) {
    renderWindow->draw(background);
    renderWindow->draw(text);
}

DefaultButton::DefaultButton() = default;

