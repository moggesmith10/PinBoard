cmake_minimum_required(VERSION 3.26)
project(PinBoard)

find_package (SFML REQUIRED system window graphics network audio)

set(CMAKE_CXX_STANDARD 17)

add_executable(PinBoard main.cpp
        Windows/MainWindow.hpp
        Windows/Window.hpp
        Windows/Themes/Default/DefaultMainWindow.cpp
        Windows/Themes/Default/DefaultMainWindow.hpp)

target_link_libraries(PinBoard PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)

