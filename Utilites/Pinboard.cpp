//
// Created by hakkerboi on 9/18/23.
//

#include "Pinboard.hpp"
#include "../Libraries/gzip/decompress.hpp"
#include "../Libraries/gzip/compress.hpp"

bool Pinboard::writeToDisk(std::string path) {

    FILE *file = fopen(path.c_str(), "wb");

    if(file == nullptr) {
        return false;
    }

    std::vector<std::byte> bytes = serialize();

    fwrite(bytes.data(), sizeof(char), bytes.size(), file);

    fclose(file);

    return true;
}

std::vector<std::byte> Pinboard::serialize() {
    std::vector <std::byte> data;
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

bool Pinboard::deserialize(std::vector<std::byte> data) {
    return false;
}

Pinboard::Pinboard(std::vector<ITextNode *> textNodes, std::vector<IImageNode *> imageNodes,
                   std::vector<IConnection *> connections) {
    this->textNodes = textNodes;
    this->imageNodes = imageNodes;
    this->connections = connections;
}
