cmake_minimum_required(VERSION 3.20)


project(tictactoe)
set(CMAKE_C_FLAGS "-Wall -std=c99 -g --coverage")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(game_sdl interface/model.c interface/main.c)
target_link_libraries(game_sdl ${SDL2_LIBRARIES})