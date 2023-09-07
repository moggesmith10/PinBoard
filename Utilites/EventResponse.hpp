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

    void setDeleteSelectedNodes(bool value);

    bool getDeleteSelectedNodes();

    void setSelectedTextBox(void *textBox);
    void *getSelectedTextBox();

private:

    void *selectedTextBox;
    enum responseValues {
        DELETE,
        PRESS,
        SELECTTEXTBOX,
        DELETESELECTEDNODES,
        RESPONSEVALUESMAX
    };
    std::bitset<RESPONSEVALUESMAX> response;
};


#endif //PINBOARD_EVENTRESPONSE_HPP
