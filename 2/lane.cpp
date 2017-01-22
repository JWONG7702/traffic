#include <cstdio>

#include "road.h"

//copy constructor for lane
Lane::Lane(const Lane& l) {
    len = l.len;
    carray = new Car*[len];

    for(int i=0;<len;i++) {
        if(l.carray + i*sizeof(Car*)) {
            Car* ptr = l.carray + i*sizeof(Car*);
            int i = ptr->geti();
            int j = ptr->getj();
            int v = ptr->velocity();
            int m = ptr->mode();
            int d = car->done();
            Car* temp = new Car(i, j, v, m, d);
            carray[i] = temp;
    }
}

//add a car at the start of a lane
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
