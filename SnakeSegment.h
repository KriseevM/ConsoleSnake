//
// Created by k17 on 18.05.2022.
//

#ifndef CONSOLESNAKE_SNAKESEGMENT_H
#define CONSOLESNAKE_SNAKESEGMENT_H

// Segments are organized in kind of linked list.
// There's a first one - head and each segment has a pointer or reference to the next one.
// The last one is a tail which just contains nullptr instead of another segment.
//
// Fields:
// x position : int (has a getter)
// y position : int (has a getter)
// follower : SnakeSegment*
// Methods:
// Draw - draw a segment
// Hide - draw a space instead of a segment
// DrawAll - calls Draw on a segment and on each segment after it
// HideAll - calls Hide on a segment and on each segment after it
// MoveTo (x : int, y : int) - moves a segment to specified position, and then calls recursively Move on follower

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
