//
// Created by hakkerboi on 9/18/23.
//

#include <fstream>
#include "Pinboard.hpp"
#include "../Libraries/gzip/decompress.hpp"
#include "../Libraries/gzip/compress.hpp"
#include "StringUtils.hpp"
#include "../Visual/Themes/Default/DefaultTextNode.hpp"
#include "../Visual/Themes/Default/DefaultImageNode.hpp"

bool Pinboard::writeToDisk(std::string path) {

    FILE *file = fopen(path.c_str(), "wb");

    if(file == nullptr) {
        return false;
    }

    std::string data = serialize();

    std::ofstream out(path, std::ios::out | std::ios::binary);
    //out << gzip::compress(data.c_str(), data.length());
    out << data;

    fclose(file);

    return true;
}

std::string Pinboard::serialize() {
    std::string data;
    for (auto &textNode : textNodes) {
        auto serialized = textNode->serialize();
        data.insert(data.end(), serialized.begin(), serialized.end());
    }
    for (auto &imageNode : imageNodes) {
        auto serialized = imageNode->serialize();
        data.insert(data.end(), serialized.begin(), serialized.end());
    }

    return data;
}

bool Pinboard::deserialize(std::string data) {
    for(auto &textNode : textNodes){
        delete textNode;
    }
    for(auto &imageNode : imageNodes){
        delete imageNode;
    }
    textNodes.clear();
    imageNodes.clear();

    std::string info = std::string((char *) data.data());

    std::vector <std::string> objects = StringUtils::split(info, (char) SERIALIZEABLE_OBJECT_DELIMITER);

    for(std::string object : objects){
        std::vector <std::string> values = StringUtils::split(object, (char) SERIALIZEABLE_VALUE_ENDER);

        std::string type = StringUtils::findParameter(object, "type");
        std::string theme = StringUtils::findParameter(object, "theme");

        if (theme == "default") {
            if (type == "text") {
                ITextNode *node = new DefaultTextNode(globals);
                node->deserialize(object);
                textNodes.push_back(node);
            } else if (type == "image") {
                IImageNode *node = new DefaultImageNode();
                node->deserialize(object);
                imageNodes.push_back(node);
            }
        }
    }

    return true;
}

Pinboard::Pinboard(std::vector<ITextNode *> textNodes, std::vector<IImageNode *> imageNodes,
                   std::vector<IConnection *> connections, Globals *globals) {
    this->textNodes = textNodes;
    this->imageNodes = imageNodes;
    this->connections = connections;
    this->globals = globals;
}

bool Pinboard::loadFromDisk(std::string path) {
    FILE *file = fopen(path.c_str(), "rb");

    if(file == nullptr) {
        return false;
    }

    std::ifstream in(path, std::ios::in | std::ios::binary);

    deserialize(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));

    return true;
}
