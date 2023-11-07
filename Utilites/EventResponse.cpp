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
    selectedObject = nullptr;
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

bool EventResponse::getDeleteSelectedConnections() {
    return response[DELETE_SELECTED_CONNECTIONS];
}

void EventResponse::setDeleteSelectedConnections(bool value) {
    response[DELETE_SELECTED_CONNECTIONS] = value;
}

void EventResponse::setDeselectTextbox(bool value) {
    response[DESELECT_TEXTBOX] = value;
}

bool EventResponse::getDeselectTextbox() {
    return response[DESELECT_TEXTBOX];
}

sf::Color EventResponse::changeConnectionColor() {
    return sf::Color();
}

void EventResponse::setChangeConnectionColor(sf::Color color) {
    this->connectionColor = color;
    response[CHANGE_CONNECTION_COLOR] = true;
}

bool EventResponse::getChangeConnectionColor() {
    return response[CHANGE_CONNECTION_COLOR];
}

void EventResponse::setMoveNode(bool value) {
    response[MOVE_NODE] = value;
}

bool EventResponse::getMoveNode() {
    return response[MOVE_NODE];
}

void EventResponse::setOpenSaveLoadWindow(bool value) {
    response[OPEN_SAVE_LOAD_WINDOW] = value;
}

bool EventResponse::getOpenSaveLoadWindow() {
    return response[OPEN_SAVE_LOAD_WINDOW];
}

void EventResponse::setCreateTextNode(bool value) {
    response[CREATE_TEXT_NODE] = value;
}

bool EventResponse::getCreateTextNode() {
    return response[CREATE_TEXT_NODE];
}
