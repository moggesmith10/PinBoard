//
// Created by hakkerboi on 9/20/23.
//

#include <sstream>
#include "StringUtils.hpp"
#include "Serializeable.hpp"

std::vector<std::string> StringUtils::split(const std::string &s, char delimiter){
    std::vector<std::string> splits;
    std::string split;
    std::istringstream ss(s);
    while (std::getline(ss, split, delimiter))
    {
        splits.push_back(split);
    }
    return splits;
}

std::string StringUtils::findParameter(std::string data, std::string parameterName) {
    auto start = data.find(parameterName + SERIALIZEABLE_VALUE_DEFINER);
    auto end = data.find(SERIALIZEABLE_VALUE_ENDER, start);

    return data.substr(start + parameterName.length() + 1, end - start - parameterName.length() - 1);
}
