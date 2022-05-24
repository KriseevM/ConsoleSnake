#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#pragma once
#include "Game.h"
#include "MainMenu.h"

class GameRunner
{
public:
    GameRunner();
    ~GameRunner();
    void Run();
private:
    void ShowScoreWindow(int score);
    Game *game;
    MainMenu *mainMenu;
    WINDOW *scoreWindow;
    
};

#endif