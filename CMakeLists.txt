cmake_minimum_required(VERSION 3.26)
project(PinBoard)

find_package(SFML REQUIRED system window graphics network audio)
find_package(ZLIB REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(PinBoard main.cpp
        Windows/IMainWindow.hpp
        Windows/IWindow.hpp
        Windows/Themes/Default/DefaultMainWindow.cpp
        Windows/Themes/Default/DefaultMainWindow.hpp
        Visual/IDrawable.hpp
        Visual/IContextMenu.hpp
        Visual/Themes/Default/DefaultMainWindowContextMenu.cpp
        Visual/Themes/Default/DefaultMainWindowContextMenu.hpp
        Utilites/CursorUtilities.cpp
        Utilites/CursorUtilities.hpp
        Visual/IContextMenuItem.hpp
        Visual/Themes/Default/DefaultButton.cpp
        Visual/Themes/Default/DefaultButton.hpp
        Utilites/FontUtilities.cpp
        Utilites/FontUtilities.hpp
        Utilites/Globals.cpp
        Utilites/Globals.hpp
        Visual/ITextNode.hpp
        Visual/Themes/Default/DefaultTextNode.cpp
        Visual/Themes/Default/DefaultTextNode.hpp
        Utilites/EventResponse.cpp
        Utilites/EventResponse.hpp
        Visual/ITextBox.hpp
        Visual/Themes/Default/DefaultTextBox.cpp
        Visual/Themes/Default/DefaultTextBox.hpp
        Visual/IConnection.hpp
        Visual/Themes/Default/DefaultConnection.cpp
        Visual/Themes/Default/DefaultConnection.hpp
        Visual/IEventHandler.hpp
        Visual/ISelectable.hpp
        Visual/Themes/Default/DefaultColorSelector.cpp
        Visual/Themes/Default/DefaultColorSelector.hpp
        Visual/IColorSelector.hpp
        Visual/IImageNode.hpp
        Visual/Themes/Default/DefaultImageNode.cpp
        Visual/Themes/Default/DefaultImageNode.hpp
        Visual/INode.hpp
        Utilites/Pinboard.cpp
        Utilites/Pinboard.hpp
        Utilites/Serializeable.hpp
        Windows/ISaveLoadWindow.hpp
        Windows/Themes/Default/DefaultSaveLoadWindow.cpp
        Windows/Themes/Default/DefaultSaveLoadWindow.hpp
        Libraries/gzip/utils.hpp
        Libraries/gzip/version.hpp
        Utilites/StringUtils.cpp
        Utilites/StringUtils.hpp
        Utilites/RandomNumberGenerator.cpp
        Utilites/RandomNumberGenerator.hpp)

add_custom_command(TARGET PinBoard PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Fonts/ $<TARGET_FILE_DIR:PinBoard>/Fonts)
add_custom_command(TARGET PinBoard PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Resources/ $<TARGET_FILE_DIR:PinBoard>/Resources)

target_link_libraries(PinBoard PRIVATE sfml-audio sfml-graphics sfml-network sfml-system ZLIB::ZLIB)

