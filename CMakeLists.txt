cmake_minimum_required(VERSION 3.13)
project(Game2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game2048 main.cpp GameModel.cpp GameModel.h CellGenerator.cpp CellGenerator.h)