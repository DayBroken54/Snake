cmake_minimum_required(VERSION 3.28.3)
project(snake)

add_library(tile_obj OBJECT
    ../src/Tile.cpp
)

target_include_directories(tile_obj PRIVATE
    ../include
)
