cmake_minimum_required(VERSION 3.23)
project(ConsoleSnake CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConsoleSnake main.cpp SnakeSegment.cpp SnakeSegment.h)
target_link_libraries(ConsoleSnake ncurses)