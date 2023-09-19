//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_PINBOARD_HPP
#define PINBOARD_PINBOARD_HPP


#include "../Visual/INode.hpp"
#include "../Visual/IConnection.hpp"
#include "../Visual/IImageNode.hpp"

class Pinboard : public Serializeable {
public:
    Pinboard(std::vector<ITextNode*> textNodes, std::vector<IImageNode*> imageNodes, std::vector<IConnection*> connections);
    std::vector<std::byte> serialize() override;
    bool deserialize(std::vector<std::byte> data) override;
    bool writeToDisk(std::string path);

    std::vector<ITextNode*> textNodes;
    std::vector<IImageNode*> imageNodes;
    std::vector<IConnection*> connections;
};


#endif //PINBOARD_PINBOARD_HPP
