#include <iostream>
#include "Windows/IWindow.hpp"
#include "Windows/Themes/Warm/WarmMainWindow.hpp"
#include "Utilites/Globals.hpp"

int main() {
    Globals *globals = new Globals();
    IWindow *mainWindow = new WarmMainWindow(globals);
    while (mainWindow->renderWindow->isOpen()) {
        mainWindow->handleEvents();
        mainWindow->draw();
    }
    return 0;
}
