#include <cstdio>

#include "road.h"

int Car::getFrontPos(Car *c) {
    return this->front->pos;
}

int Car::getFrontVel(Car *c) {
    return this->front->vel;
}
