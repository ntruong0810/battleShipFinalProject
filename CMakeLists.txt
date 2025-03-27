cmake_minimum_required(VERSION 3.28)
project(final)

set(CMAKE_CXX_STANDARD 17)

add_executable(final main.cpp
        Board.cpp
        Board.h
        Ship.cpp
        Ship.h
        GraphicBoard.cpp
        GraphicBoard.h
        BattleshipPlayer.cpp
        BattleshipPlayer.h)
target_link_libraries(final sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)