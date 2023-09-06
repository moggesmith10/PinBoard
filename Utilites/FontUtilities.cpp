//
// Created by hakkerboi on 9/4/23.
//

#include "FontUtilities.hpp"

sf::Font *FontUtilities::getFont(u_char font) {
    return this->fontsArray[font];
}

FontUtilities::FontUtilities() {
    this->fontsArray = std::vector<sf::Font *>(FONTLEN);
    this->fontsArray[(u_char) FontUtilities::NotoSansMedium] = loadFont("NotoSans", "NotoSans-Medium");
}

sf::Font *FontUtilities::loadFont(std::string family, std::string name) {
    sf::Font *font = new sf::Font();
    font->loadFromFile("Fonts/" + family + "/" + name + ".ttf");
    return font;
}
