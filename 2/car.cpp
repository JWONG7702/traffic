#include <cstdio>

#include "road.h"

int Car::getFrontPos(Car* c) {
    return this->front->pos;
}

int Car::getFrontVel(Car* c) {
    return this->front->vel;
}

void Car::setFront(Car* c) {
    this.front = c;
}

void Car::setBack(Car* c) {
    this.back = c;
}
