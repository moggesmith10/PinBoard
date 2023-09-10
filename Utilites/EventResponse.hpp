//
// Created by hakkerboi on 9/6/23.
//

#ifndef PINBOARD_EVENTRESPONSE_HPP
#define PINBOARD_EVENTRESPONSE_HPP


#include <bitset>

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

    void setDeleteSelectedNodes(bool value);

    bool getDeleteSelectedNodes();

    void setSelectTextBox(void *object);
    bool getSelectTextBox();
    void *getSelectedObject();

private:

    void *selectedObject;
    enum responseValues {
        DELETE,
        PRESS,
        SELECT_TEXTBOX,
        DELETE_SELECTED_NODES,
        CONNECT_TO,
        RESPONSE_VALUES_MAX
    };
    std::bitset<RESPONSE_VALUES_MAX> response;
};


#endif //PINBOARD_EVENTRESPONSE_HPP
