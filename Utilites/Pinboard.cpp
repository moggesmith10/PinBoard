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
#include "../Visual/Themes/Default/DefaultConnection.hpp"

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
    for(auto &connection : connections){
        auto serialized = connection->serialize();
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

    std::string info = data;

    std::vector <std::string> objects = StringUtils::breakUpObject(info, (char) SERIALIZEABLE_OBJECT_DELIMITER);

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
            else if(type == "connection"){
                INode* node1 = nullptr;
                INode* node2 = nullptr;

                int node1Id = std::stoi(StringUtils::findParameter(object, "node1"));
                int node2Id = std::stoi(StringUtils::findParameter(object, "node2"));

                for(INode* node : textNodes){
                    if(node->id == node1Id){
                        node1 = node;
                    }
                    else if(node->id == node2Id){
                        node2 = node;
                    }
                }
                if(node1 == nullptr || node2 == nullptr) {
                    for (INode *node: imageNodes) {
                        if (node->id == node1Id) {
                            node1 = node;
                        } else if (node->id == node2Id) {
                            node2 = node;
                        }
                    }
                }

                IConnection* connection = new DefaultConnection(node1, node2);
                connection->deserialize(object);
                connections.push_back(connection);
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

    std::string fileData;

    while (in.peek() != EOF){
        fileData += in.get();
    }

    deserialize(fileData);

    return true;
}
