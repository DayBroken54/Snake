cmake_minimum_required(VERSION 3.28.3)
project(snake)

add_library(snake_obj OBJECT
    ../src/Snake.cpp
)

target_include_directories(snake_obj PRIVATE
    ../include
)
