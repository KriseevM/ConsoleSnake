//
// Created by k17 on 18.05.2022.
//

#include "SnakeSegment.h"
#include "GameColors.h"

SnakeSegment::SnakeSegment(int x, int y, int length, WINDOW *window) : x(x), y(y) {

    this->window = window;
    follower = length <= 1 ? nullptr : new SnakeSegment(x-1, y, length - 1, window);
}

void SnakeSegment::DrawAll() {
    if(follower != nullptr){
        follower->DrawAll();
    }
    this->draw();
}

void SnakeSegment::HideAll() {
    this->Hide();
    if(follower != nullptr){
        follower->HideAll();
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

SnakeSegment *SnakeSegment::getFollower() {
    return this->follower;
}

int SnakeSegment::getY() {
    return this->y;
}

bool SnakeHeadSegment::isDead() {
    return this->_isDead;
}


void SnakeHeadSegment::draw() {
    wmove(window, this->y, this->x);
    wattron(window, COLOR_PAIR(GameColors::SnakeHeadPair));
    waddch(window, (_isDead ? 'x' : 'O')|A_NORMAL);
    wattroff(window, COLOR_PAIR(GameColors::SnakeHeadPair));
}

void SnakeHeadSegment::MoveTo(int newX, int newY) {
    if(newX + 1 >= getmaxx(window) || newY + 1 >= getmaxy(window) || newX <= 0 || newY <= 0)
    {
        _isDead = true;
        return;
    }
    auto ref = this->follower;
    while(ref != nullptr) {
        if(ref->getX() == this->x && ref->getY() == this->y)
        {
            _isDead = true;
            return;
        }
        ref = ref->getFollower();
    }
    SnakeSegment::MoveTo(newX, newY);
}

void SnakeSegment::Grow() {
    if(follower == nullptr)
    {
        follower = new  SnakeSegment(this->x, this->y, 0, window);
    }
    else
    {
        follower->Grow();
    }
}

SnakeSegment::~SnakeSegment() {
    if(follower != nullptr)
        delete follower;
}

