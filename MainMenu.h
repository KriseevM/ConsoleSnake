#ifndef MAINMENU_H
#define MAINMENU_H

#include <ncurses.h>
#include <string>
#include <vector>

enum MenuResult {
    MENU_PLAY = 0,
    MENU_QUIT
};

class MainMenu
{
public:
    MainMenu(int width = 50, int height = 30);
    MenuResult Show();
    WINDOW *GetWindow();
    void PrintMenuOptions(const size_t selected);
    ~MainMenu();
private:
    std::vector<std::string> menuItems = {"Play", "Quit"};
    WINDOW *menuWindow;
    int winWidth;
    int winHeight;
    
};

#endif