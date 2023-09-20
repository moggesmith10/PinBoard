//
// Created by hakkerboi on 9/20/23.
//

#ifndef PINBOARD_STRINGUTILS_HPP
#define PINBOARD_STRINGUTILS_HPP


#include <string>
#include <vector>

class StringUtils {
public:
    static std::vector<std::string> split(const std::string& s, char delimiter);
    static std::string findParameter(std::string data, std::string parameterName);
};


#endif //PINBOARD_STRINGUTILS_HPP
