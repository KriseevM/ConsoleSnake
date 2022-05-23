#include "MainMenu.h"
#include "GameColors.h"
MainMenu::MainMenu(int width, int height) : winWidth(width), winHeight(height)
{
    this->menuWindow = newwin(height, width, (getmaxy(stdscr) - height) / 2, (getmaxx(stdscr) - width) / 2);
    nodelay(this->menuWindow, false);
    keypad(this->menuWindow, true);
}
MenuResult MainMenu::Show()
{
    wattron(menuWindow, A_STANDOUT);
    wattron(menuWindow, COLOR_PAIR(GameColors::MenuWindowPair));
    wclear(menuWindow);
    wbkgd(menuWindow, COLOR_PAIR(GameColors::MenuWindowPair));
    box(this->menuWindow, 0, 0);
    wattroff(menuWindow, A_STANDOUT);
    wattroff(menuWindow, COLOR_PAIR(GameColors::MenuWindowPair));
    size_t selectedIndex = 0;
    int c;
    do {
        PrintMenuOptions(selectedIndex);
        wrefresh(menuWindow);
        c = wgetch(menuWindow);
        switch (c)
        {
            case KEY_UP:
                if(selectedIndex > 0)
                    selectedIndex -= 1;
                break;
            case KEY_DOWN:
                if(selectedIndex < menuItems.size() - 1)
                    selectedIndex += 1;
                break;
        }
    }
    while(c != KEY_ENTER && c != '\n' && c != '\r');
    return static_cast<MenuResult>(selectedIndex);
}

void MainMenu::PrintMenuOptions(const size_t selectedIndex)
{
    for(size_t i = 0; i < menuItems.size(); i++) {
        wattron(this->menuWindow, 
            COLOR_PAIR(selectedIndex == i ? GameColors::MenuSelectedPair : GameColors::MenuUnselectedPair));
        mvwprintw(menuWindow, (winHeight - menuItems.size()) / 2 + i, (winWidth - menuItems[i].size()) / 2, "%s", menuItems[i].c_str());
        wattroff(this->menuWindow, 
            COLOR_PAIR(selectedIndex == i ? GameColors::MenuSelectedPair : GameColors::MenuUnselectedPair));
    }
}

WINDOW * MainMenu::GetWindow()
{
    return menuWindow;
}
MainMenu::~MainMenu()
{
    delwin(menuWindow);
}