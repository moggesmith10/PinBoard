//
// Created by hakkerboi on 10/19/23.
//

#ifndef PINBOARD_IANIMATEABLE_HPP
#define PINBOARD_IANIMATEABLE_HPP


#include "IDrawable.hpp"

class IAnimateable : public IDrawable {
protected:
    int frame = 0;
public:
    bool started = false;
    bool finished = false;
    int frames = 0;
    virtual void iterate() = 0;
    virtual void start() = 0;
};


#endif //PINBOARD_IANIMATEABLE_HPP
