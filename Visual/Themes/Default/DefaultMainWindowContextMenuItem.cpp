//
// Created by hakkerboi on 9/4/23.
//

#include "DefaultMainWindowContextMenuItem.hpp"
#include "../../../Utilites/CursorUtilities.hpp"

DefaultMainWindowContextMenuItem::DefaultMainWindowContextMenuItem(
                                                                   std::string text, Globals *globals, sf::RenderWindow *renderWindow, sf::Vector2f position) {
    background = sf::RectangleShape(sf::Vector2f(180, 40));
    background.setPosition(position);
    this->renderWindow = renderWindow;
    this->globals = globals;
    this->text = sf::Text(text, *globals->fontUtilites->getFont(FontUtilities::NotoSansMedium), 20);
    this->text.setPosition(position.x + 10, position.y + 10);
    this->text.setFillColor(sf::Color::Black);
}

void DefaultMainWindowContextMenuItem::draw() {
     renderWindow->draw(background);
     renderWindow->draw(text);
}

bool DefaultMainWindowContextMenuItem::isHovered(sf::Vector2f position) {
    return background.getGlobalBounds().contains(position);
}

DefaultMainWindowContextMenuItem::DefaultMainWindowContextMenuItem() = default;

