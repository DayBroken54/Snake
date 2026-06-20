cmake_minimum_required(VERSION 3.28.3)
project(snake)

find_package(pybind11 REQUIRED)

add_library(game SHARED
    ../src/Game_State.cpp
    ../src/pybind11.cpp
    ../src/Snake.cpp
    ../src/Tile.cpp
)

target_link_libraries(game PRIVATE pybind11::module)

target_include_directories(game PRIVATE
    ../include
)