//
// Created by k17 on 18.05.2022.
//

#include "SnakeSegment.h"
#include "GameColors.h"

SnakeSegment::SnakeSegment(int x, int y, int length, WINDOW *window) : x(x), y(y) {
    if(length <= 1)
    {
        follower = nullptr;
        return;
    }
    this->window = window;
    follower = new SnakeSegment(x-1, y, length - 1, window);
}

void SnakeSegment::DrawAll() {
    auto ref = this->follower;
    while(ref != nullptr)
    {
        ref->draw();
        ref = ref->follower;
    }
    this->draw();
}

void SnakeSegment::HideAll() {
    this->Hide();
    auto ref = this->follower;
    while(ref != nullptr)
    {
        ref->Hide();
        ref = ref->follower;
    }
}

void SnakeSegment::MoveTo(int newX, int newY) {
    if(follower != nullptr)
    {
        follower->MoveTo(this->x, this->y);
    }
    this->x = newX;
    this->y = newY;
}

void SnakeSegment::draw() {
    wmove(window, this->y, this->x);
    wattron(window, COLOR_PAIR(GameColors::SnakePair));
    waddch(window, 'o'|A_NORMAL);
    wattroff(window, COLOR_PAIR(GameColors::SnakePair));
}
void SnakeSegment::Hide() {
    wmove(window, this->y, this->x);
    waddch(window, ' '|A_NORMAL);
}

int SnakeSegment::getX() {
    return this->x;
}

int SnakeSegment::getY() {
    return this->y;
}

bool SnakeHeadSegment::isDead() {
    return this->_isDead;
}


void SnakeHeadSegment::draw() {
    wmove(window, this->y, this->x);
    waddch(window, (_isDead ? 'X' : 'O')|A_NORMAL);

}

void SnakeHeadSegment::MoveTo(int newX, int newY) {
    if(newX >= getmaxx(window) || newY >= getmaxy(window))
    {
        _isDead = true;
        return;
    }
    SnakeSegment::MoveTo(newX, newY);
}

SnakeSegment::~SnakeSegment() {
    delete follower;
}

