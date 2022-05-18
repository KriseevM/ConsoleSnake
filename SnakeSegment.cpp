//
// Created by k17 on 18.05.2022.
//

#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(int x, int y, int length) : x(x), y(y) {
    if(length <= 1)
    {
        follower = nullptr;
        return;
    }
    follower = new SnakeSegment(x+1, y, length - 1);
}

void SnakeSegment::DrawAll() {
    this->Draw();
    auto ref = this->follower;
    while(ref != nullptr)
    {
        ref->Draw();
        ref = ref->follower;
    }
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