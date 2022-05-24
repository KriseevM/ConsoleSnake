#include <ncurses.h>
#include "GameRunner.h"
#include "GameColors.h"
#include <iostream>

int main() {
    initscr();
    start_color();
    GameColors::initialize();
    cbreak();
    nodelay(stdscr, false);
    curs_set(0);
    refresh();
    int maxY = getmaxy(stdscr);
    int maxX = getmaxx(stdscr);
    if(maxY < 10|| maxX < 30) {
        endwin();
        std::cerr << "Window size must be at least 10 rows and 30 columns" << std::endl;
        return -1;
    }
    GameRunner *runner = new GameRunner();
    runner->Run();
    delete runner;
    endwin();
    return 0;
}