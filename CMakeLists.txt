cmake_minimum_required(VERSION 3.23)
project(ConsoleSnake CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConsoleSnake main.cpp GameColors.h GameColors.cpp SnakeSegment.cpp SnakeSegment.h Game.h Game.cpp MainMenu.h MainMenu.cpp GameRunner.h GameRunner.cpp)
target_link_libraries(ConsoleSnake ncurses)