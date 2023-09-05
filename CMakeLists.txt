cmake_minimum_required(VERSION 3.26)
project(PinBoard)

find_package (SFML REQUIRED system window graphics network audio)

set(CMAKE_CXX_STANDARD 17)

add_executable(PinBoard main.cpp
        Windows/IMainWindow.hpp
        Windows/IWindow.hpp
        Windows/Themes/Default/DefaultMainWindow.cpp
        Windows/Themes/Default/DefaultMainWindow.hpp
        Visual/IDrawable.hpp
        Visual/IContextMeny.hpp
        Visual/Themes/Default/DefaultMainWindowContextMenu.cpp
        Visual/Themes/Default/DefaultMainWindowContextMenu.hpp
        Utilites/CursorUtilities.cpp
        Utilites/CursorUtilities.hpp
        Visual/IContextMenuItem.hpp
        Visual/Themes/Default/DefaultMainWindowContextMenuItem.cpp
        Visual/Themes/Default/DefaultMainWindowContextMenuItem.hpp
        Utilites/FontUtilities.cpp
        Utilites/FontUtilities.hpp
        Utilites/Globals.cpp
        Utilites/Globals.hpp
        Visual/INode.hpp)

add_custom_command(TARGET PinBoard PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Fonts/ $<TARGET_FILE_DIR:PinBoard>/Fonts)

target_link_libraries(PinBoard PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)

