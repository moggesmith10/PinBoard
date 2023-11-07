//
// Created by hakkerboi on 9/18/23.
//

#ifndef PINBOARD_PINBOARD_HPP
#define PINBOARD_PINBOARD_HPP


#include "../Visual/INode.hpp"
#include "../Visual/IConnection.hpp"
#include "../Visual/IImageNode.hpp"
#include "Globals.hpp"

class Pinboard : public Serializeable {
public:
    Pinboard(std::vector<ITextNode*> textNodes, std::vector<IImageNode*> imageNodes, std::vector<IConnection*> connections, Globals* globals);
    std::string serialize() override;
    bool deserialize(std::string) override;
    bool writeToDisk(std::string path);
    bool loadFromDisk(std::string path);

    std::vector<ITextNode*> textNodes;
    std::vector<IImageNode*> imageNodes;
    std::vector<IConnection*> connections;

    Globals* globals;
};


#endif //PINBOARD_PINBOARD_HPP
