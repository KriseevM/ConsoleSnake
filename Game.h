#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "SnakeSegment.h"
class Game
{
public:
    Game();
    int Play();
    ~Game();
private:
    void DrawFruit(int fruitX, int fruitY);
    void PlaceFruit(int &x, int &y, SnakeHeadSegment *snake);
    enum Rotations { 
        ROT_NONE = -1,
        ROT_UP = 0, 
        ROT_DOWN = 1, 
        ROT_LEFT = 2, 
        ROT_RIGHT = 3
    };
    Rotations getInput();
    WINDOW *gameWindow;
};

#endif