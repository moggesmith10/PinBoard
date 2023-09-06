//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_FONTUTILITIES_HPP
#define PINBOARD_FONTUTILITIES_HPP


#include <string>
#include <SFML/Graphics/Font.hpp>

class FontUtilities {
public:
    sf::Font *getFont(u_char font);

    enum fonts {
        NotoSansMedium,
        FONTLEN
    };

    FontUtilities();

    std::vector<sf::Font *> fontsArray;
private:
    sf::Font *loadFont(std::string family, std::string name);
};


#endif //PINBOARD_FONTUTILITIES_HPP
