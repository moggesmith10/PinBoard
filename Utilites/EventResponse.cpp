//
// Created by hakkerboi on 9/6/23.
//

#include "EventResponse.hpp"

void EventResponse::setDelete(bool value) {
    response[DELETE] = value;
}

bool EventResponse::getDelete() {
    return response[DELETE];
}

EventResponse::EventResponse() {
    response.reset();
}

void EventResponse::clear() {
    response.reset();
}

void EventResponse::setPress(bool value) {
    response[PRESS] = value;
}

bool EventResponse::getPress() {
    return response[PRESS];
}

void EventResponse::setSelectedTextBox(void *textBox) {
    selectedTextBox = textBox;
    if(textBox == nullptr)
        response[SELECTTEXTBOX] = false;
    else
        response[SELECTTEXTBOX] = true;
}

void *EventResponse::getSelectedTextBox() {
    if(!response[SELECTTEXTBOX])
        return nullptr;
    return selectedTextBox;
}

void EventResponse::setDeleteSelectedNodes(bool value) {
    response[DELETESELECTEDNODES] = value;
}

bool EventResponse::getDeleteSelectedNodes() {
    return response[DELETESELECTEDNODES];
}
