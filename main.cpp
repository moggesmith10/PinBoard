#include <iostream>
#include "Windows/IWindow.hpp"
#include "Windows/Themes/Default/DefaultMainWindow.hpp"
#include "Utilites/Globals.hpp"

int main() {
    Globals *globals = new Globals();
    IWindow *mainWindow = new DefaultMainWindow(globals);
    while (mainWindow->renderWindow->isOpen()) {
        mainWindow->handleEvents();
        mainWindow->draw();
    }
    return 0;
}
