//
// Created by hakkerboi on 9/6/23.
//

#ifndef PINBOARD_EVENTRESPONSE_HPP
#define PINBOARD_EVENTRESPONSE_HPP


#include <bitset>
#include <SFML/Graphics/Color.hpp>

class EventResponse {
public:
    EventResponse();

    void clear();

    void setDelete(bool value);

    void setPress(bool value);

    bool getDelete();

    bool getPress();

    bool getConnectTo();

    void setConnectTo(void *object);

    void setDeselectTextbox(bool value);

    bool getDeselectTextbox();

    void setDeleteSelectedNodes(bool value);

    void setChangeConnectionColor(sf::Color color);

    bool getChangeConnectionColor();

    sf::Color changeConnectionColor();

    bool getDeleteSelectedNodes();

    bool getDeleteSelectedConnections();

    void setDeleteSelectedConnections(bool value);

    void setSelectTextBox(void *object);

    bool getSelectTextBox();

    void *getSelectedObject();

    void setMoveNode(bool value);

    bool getMoveNode();

    void setCreateTextNode(bool value);

    bool getCreateTextNode();

    void setOpenSaveLoadWindow(bool value);

    bool getOpenSaveLoadWindow();

    sf::Color connectionColor;

private:

    void *selectedObject;
    enum responseValues {
        DELETE,
        PRESS,
        SELECT_TEXTBOX,
        DELETE_SELECTED_NODES,
        DELETE_SELECTED_CONNECTIONS,
        CONNECT_TO,
        DESELECT_TEXTBOX,
        CHANGE_CONNECTION_COLOR,
        MOVE_NODE,
        OPEN_SAVE_LOAD_WINDOW,
        CREATE_TEXT_NODE,
        RESPONSE_VALUES_MAX
    };
    std::bitset<RESPONSE_VALUES_MAX> response;
};


#endif //PINBOARD_EVENTRESPONSE_HPP
