#include <ncurses.h>
#include <vector>
#include <string>
#include "MainMenu.h"
#include "GameColors.h"
#include <thread>
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
    MainMenu *menu = new MainMenu(20, 7);
    auto s = menu->Show();
    delete menu;
    endwin();
    switch(s)
    {
        case MENU_PLAY:
            std::cout << "Playing" << std::endl;
            break;
        case MENU_QUIT:
            std::cout << "Quitting" << std::endl;
            break;
    }
    return 0;
}