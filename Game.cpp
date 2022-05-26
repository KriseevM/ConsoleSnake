#include "Game.h"
#include <thread>
#include <chrono>
#include <ctime>
#include "SnakeSegment.h"
#include "GameColors.h"

using namespace std::literals::chrono_literals;

Game::Game()
{
    srand(time(0));
    gameWindow = newwin(getmaxy(stdscr) - 2, getmaxx(stdscr) - 2, 1, 1);
    nodelay(gameWindow, true);
    keypad(gameWindow, true);
}
int Game::Play()
{
    int snakeX = 15;
    int snakeY = 5;
    int initLength = 5;
    int score = 0;
    Rotations rot = ROT_RIGHT;
    int fruitX;
    int fruitY;
    wclear(gameWindow);
    wbkgd(gameWindow, COLOR_PAIR(GameColors::GameFieldPair));
    box(gameWindow, 0, 0);
    mvwprintw(gameWindow, 0, 3, "|Score: ");
    mvwprintw(gameWindow, 0, 11, "%5d|", score);
    auto head = new SnakeHeadSegment(snakeX, snakeY, initLength, gameWindow);
    head->DrawAll();
    wrefresh(gameWindow);
    PlaceFruit(fruitX, fruitY, head);
    auto delay = 200ms;
    while(!head->isDead())
    {
        std::this_thread::sleep_for(delay);
        auto input = this->getInput();
        if(input != ROT_NONE)
        {
            rot = input;
        }
        switch(rot)
        {
            case ROT_UP:
                --snakeY;
                break;
            case ROT_DOWN:
                ++snakeY;
                break;
            case ROT_LEFT:
                --snakeX;
                break;
            case ROT_RIGHT:
                ++snakeX;
                break;
        }
        head->HideAll();
        head->MoveTo(snakeX, snakeY);
        head->DrawAll();
        if(head->getX() == fruitX && head->getY() == fruitY)
        {
            ++score;
            PlaceFruit(fruitX, fruitY, head);
            head->Grow();
            if(score % 10 == 0)
            {
                if(delay > 50ms) {
                    delay -= 50ms;
                }
            }
            mvwprintw(gameWindow, 0, 11, "%5d|", score);
        }
        DrawFruit(fruitX, fruitY);
        wrefresh(gameWindow);
    }
    wrefresh(gameWindow);
    delete head;
    return score;
}

void Game::PlaceFruit(int &fruitX, int &fruitY, SnakeHeadSegment *snake)
{
    bool isSnakeThere = false;
    do {
        fruitX = rand() % (getmaxx(gameWindow) - 6) + 3;
        fruitY = rand() % (getmaxy(gameWindow) - 6) + 3;
        isSnakeThere = snake->getX() == fruitX && snake->getY() == fruitY;
        auto ref = snake->getFollower();
        while(!isSnakeThere && ref != nullptr)
        {
            isSnakeThere = isSnakeThere || (ref->getX() == fruitX && ref->getY() == fruitY);
            ref = ref->getFollower();
        }
    } while(isSnakeThere);
}
void Game::DrawFruit(int fruitX, int fruitY)
{
    wattron(gameWindow, GameColors::FruitPair);
    mvwaddch(gameWindow, fruitY, fruitX, '@');
    wattroff(gameWindow, GameColors::FruitPair);
}
Game::Rotations Game::getInput()
{
    auto c = wgetch(gameWindow);
    switch(c)
    {
        case KEY_UP:
            return ROT_UP;
        case KEY_DOWN:
            return ROT_DOWN;
        case KEY_RIGHT:
            return ROT_RIGHT;
        case KEY_LEFT:
            return ROT_LEFT;
        default:
            return ROT_NONE;
    }
}
Game::~Game()
{
    delwin(gameWindow);
}