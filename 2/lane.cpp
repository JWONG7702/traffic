#include <cstdio>

#include "road.h"

void Lane::addCar(Car* c) {
    carray[0] = c;

    for(int j=1; j<this->size(); j++) {
        if(Car* it = this->carr()[j]) {
            c->setFront(it);
            it->setBack(c);
            break;
        }
    }
}

