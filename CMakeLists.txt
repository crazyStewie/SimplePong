cmake_minimum_required(VERSION 3.5)

project(Sample LANGUAGES CXX C)

add_subdirectory(third_party/)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_SOURCES src/main.cpp src/engine/game.cpp src/engine/gameobject.cpp src/core/pong.cpp src/core/paddle.cpp src/core/paddle.h src/core/ball.cpp src/core/ball.h)

include_directories(.)
add_executable(Sample ${MAIN_SOURCES})
target_link_libraries(Sample raylib_static)
