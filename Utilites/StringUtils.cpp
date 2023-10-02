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
    auto end = data.find_first_of(SERIALIZEABLE_VALUE_ENDER, start);

    return data.substr(start + parameterName.length() + 1, end - start - parameterName.length() - 1);
}

std::vector<std::string> StringUtils::findMultiParameter(std::string data, std::string parameterName) {
    auto start = data.find(parameterName + SERIALIZEABLE_VALUE_DEFINER);
    auto end = data.find(SERIALIZEABLE_VALUE_ENDER, start);

    std::vector<std::string> values = split(data.substr(start + parameterName.length() + 1, end - start - parameterName.length() - 1), SERIALIZEABLE_MULTIVALUE_SEPARATOR);

    return values;
}

std::vector<std::string> StringUtils::breakUpObject(const std::string &s, char delimiter) {
    std::vector<std::string> splits;

    std::string internal = s;

    while ( internal.length() > 0) {

        std::string type = findParameter(internal, "type");
        if (type == "text" || type == "connection") {
            std::string split;
            std::istringstream ss(internal);
            std::getline(ss, split, delimiter);
            splits.push_back(split);
            internal = internal.substr(split.length() + 1);
        }
        else if(type == "image"){
            int length = std::stoi(findParameter(internal, "length"));
            int contentLen = internal.find_first_of(SERIALIZEABLE_BINARY_DEFINER);
            std::string split = internal.substr(0, contentLen + length + 1);
            splits.push_back(split);
            internal = internal.substr(split.length() + 1);
        }
        else{
            break;
        }
    }

    return splits;
}
