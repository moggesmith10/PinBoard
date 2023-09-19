//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_PINBOARD_HPP
#define PINBOARD_PINBOARD_HPP


#include "../Visual/INode.hpp"
#include "../Visual/IConnection.hpp"
#include "../Visual/IImageNode.hpp"

class Pinboard : public Serializeable {
    std::vector<ITextNode*> textNodes;
    std::vector<IImageNode*> imageNodes;
    std::vector<IConnection*> connections;
public:
    std::byte* serialize() override;
    bool deserialize(std::byte* data) override;
    bool writeToDisk(std::string path);
};


#endif //PINBOARD_PINBOARD_HPP
