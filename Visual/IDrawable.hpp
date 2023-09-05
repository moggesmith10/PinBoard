//
// Created by hakkerboi on 9/4/23.
//

#ifndef PINBOARD_IDRAWABLE_HPP
#define PINBOARD_IDRAWABLE_HPP


class IDrawable {
public:
    virtual void draw(sf::RenderWindow* renderWindow) = 0;
    IDrawable() = default;
    virtual ~IDrawable() = default;
};


#endif //PINBOARD_IDRAWABLE_HPP
