#include "GameRunner.h"
#include "GameColors.h"
GameRunner::GameRunner()
{
    mainMenu = new MainMenu(20, 10);
    game = new Game();
    scoreWindow = newwin(8, 17, (getmaxy(stdscr) - 8) / 2, (getmaxx(stdscr) - 17) / 2); 
    keypad(scoreWindow, true);
}
void GameRunner::ShowScoreWindow(int score)
{
    wclear(scoreWindow);
    wbkgd(scoreWindow, COLOR_PAIR(GameColors::MenuWindowPair));
    box(scoreWindow, 0, 0);
    mvwprintw(scoreWindow, 2, 3, "Game over!");
    mvwprintw(scoreWindow, 4, 2, "Score: %d", score);
    mvwprintw(scoreWindow, 6, 2, "Press any key");
    wmove(scoreWindow, 0, 0);
    wrefresh(scoreWindow);
    wgetch(scoreWindow);
}
void GameRunner::Run()
{
    while(true){
        auto variant = mainMenu->Show();
        int score;
        switch(variant)
        {
            case MENU_PLAY:
                score = game->Play();
                ShowScoreWindow(score);
                clear();
                refresh();
                break;
            case MENU_QUIT:
                return;
        }
    }
}

GameRunner::~GameRunner()
{
    delwin(scoreWindow);
    delete game;
    delete mainMenu;
}
