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

    std::string string = gzip::compress(reinterpret_cast<const char *>(serialize()), sizeof(serialize()));

    fwrite(string.c_str(), sizeof(char), string.size(), file);

    fclose(file);

    return true;
}

std::byte *Pinboard::serialize() {
    std::vector <std::byte> data;
    for (auto &textNode : textNodes) {
        auto serialized = textNode->serialize();
        data.insert(data.end(), serialized, serialized + sizeof(serialized));
    }
    for (auto &imageNode : imageNodes) {
        auto serialized = imageNode->serialize();
        data.insert(data.end(), serialized, serialized + sizeof(serialized));
    }

    return data.data();
}

bool Pinboard::deserialize(std::byte *data) {
    return false;
}
