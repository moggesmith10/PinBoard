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

    void setConnectTo(void  *object);

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
        DESELECT_TETXBOX,
        CHANGE_CONNECTION_COLOR,
        RESPONSE_VALUES_MAX
    };
    std::bitset<RESPONSE_VALUES_MAX> response;
};


#endif //PINBOARD_EVENTRESPONSE_HPP
