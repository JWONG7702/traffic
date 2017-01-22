#include <cstdio>

#include "road.h"

//copy constructor for lane
Lane::Lane(const Lane& l) {
    len = l.len;
    carray = new Car*[len];

    for(int i=0;i<len;i++) {
        if(l.carray + i*sizeof(Car*)) {
            Car* ptr = l.carray[i];
            int i = ptr->geti();
            int j = ptr->getj();
            int v = ptr->velocity();
            int m = ptr->mode();
            int d = ptr->done();
            Car* temp = new Car(i, j, v, m, d);
            carray[i] = temp;
        }
    }
}
