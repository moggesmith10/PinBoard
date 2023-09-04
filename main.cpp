#include <iostream>
#include "Windows/Window.hpp"
#include "Windows/Themes/Default/DefaultMainWindow.hpp"

int main() {
    Window* mainWindow = new DefaultMainWindow();
    while (mainWindow->renderWindow->isOpen()) {
        mainWindow->handleEvents();
        mainWindow->draw();
    }
    return 0;
}
