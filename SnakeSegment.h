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

class SnakeSegment {
private:
    int x;
    int y;
    SnakeSegment *follower = nullptr;
public:
    SnakeSegment(int x, int y, int length);
    virtual void Draw();
    void Hide();
    void DrawAll();
    void HideAll();
    void MoveTo(int x, int y);
};

class SnakeHeadSegment : public SnakeSegment
{
public:
    SnakeHeadSegment(int x, int y, int length) : SnakeSegment(x, y, length){};
    void Draw();
};
#endif //CONSOLESNAKE_SNAKESEGMENT_H
