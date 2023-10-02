//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_SERIALIZEABLE_HPP
#define PINBOARD_SERIALIZEABLE_HPP
#define SERIALIZEABLE_VALUE_DEFINER ':'
#define SERIALIZEABLE_VALUE_SEPARATOR ';'
#define SERIALIZEABLE_BINARY_DEFINER '|'
#define SERIALIZEABLE_VALUE_ENDER '\n'
#define SERIALIZEABLE_MULTIVALUE_SEPARATOR ','
#define SERIALIZEABLE_OBJECT_DELIMITER '%'

#include <string>

class Serializeable {
public:
    virtual std::string serialize() = 0;
    virtual bool deserialize(std::string data) = 0;
};


#endif //PINBOARD_SERIALIZEABLE_HPP
