//
// Created by k17 on 18.05.2022.
//

#ifndef CONSOLESNAKE_SNAKESEGMENT_H
#define CONSOLESNAKE_SNAKESEGMENT_H

#include <ncurses.h>

class SnakeSegment {
protected:
    int x;
    int y;
    SnakeSegment *follower = nullptr;
    WINDOW* window;
public:
    SnakeSegment(int x, int y, int length = 5, WINDOW *window = stdscr);
    virtual void draw();
    void Hide();
    void DrawAll();
    void HideAll();
    virtual void MoveTo(int x, int y);
    int getX();
    int getY();
    void Grow();
    SnakeSegment *getFollower();
    virtual ~SnakeSegment();
};

class SnakeHeadSegment : public SnakeSegment
{
private:
    bool _isDead = false;
public:
    SnakeHeadSegment(int x, int y, int length, WINDOW* w) : SnakeSegment(x, y, length, w){};
    void draw() override;
    void MoveTo(int x, int y) override;
    bool isDead();
    void Kill();
};
#endif //CONSOLESNAKE_SNAKESEGMENT_H
