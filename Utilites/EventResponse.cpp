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

void EventResponse::setSelectTextBox(void *object) {
    selectedObject = object;
    if(object == nullptr)
        response[SELECT_TEXTBOX] = false;
    else
        response[SELECT_TEXTBOX] = true;
}

void *EventResponse::getSelectedObject() {
    if(!response[SELECT_TEXTBOX])
        return nullptr;
    return selectedObject;
}

void EventResponse::setDeleteSelectedNodes(bool value) {
    response[DELETE_SELECTED_NODES] = value;
}

bool EventResponse::getDeleteSelectedNodes() {
    return response[DELETE_SELECTED_NODES];
}

bool EventResponse::getConnectTo() {
    return response[CONNECT_TO];
}

void EventResponse::setConnectTo(void *object) {
    selectedObject = object;
    if(object == nullptr)
        response[CONNECT_TO] = false;
    else
        response[CONNECT_TO] = true;
}

bool EventResponse::getSelectTextBox() {
    return response[SELECT_TEXTBOX];
}
