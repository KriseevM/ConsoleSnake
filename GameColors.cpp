#include "GameColors.h"
#include <ncurses.h>

void GameColors::initialize()
{
    init_pair(GameColors::MenuWindowPair, COLOR_WHITE, COLOR_BLACK);
    init_pair(GameColors::MenuSelectedPair, COLOR_WHITE, COLOR_BLUE);
    init_pair(GameColors::MenuUnselectedPair, COLOR_WHITE, COLOR_BLACK);
    init_pair(GameColors::GameFieldPair, COLOR_WHITE, COLOR_GREEN);
    init_pair(GameColors::SnakePair, COLOR_WHITE, COLOR_GREEN);
    init_pair(GameColors::FruitPair, COLOR_RED, COLOR_GREEN);
    init_pair(GameColors::SnakeHeadPair, COLOR_BLUE, COLOR_GREEN);
}