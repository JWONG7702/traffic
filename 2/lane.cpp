#include <cstdio>

#include "road.h"

//copy constructor for lane
Lane::Lane(const Lane& l) {
    len = l.len; //set length and initialize a new Car* array
    carray = new Car*[len];

    for(int i=0;i<len;i++) {
        //loop through Car* and check if there are cars
        if(l.carray + i*sizeof(Car*)) {
            //whenever there are, get pointers to them
            Car* ptr = l.carray[i];
            int i = ptr->geti();
            int j = ptr->getj();
            int v = ptr->velocity();
            int m = ptr->mode();
            int d = ptr->done();
            //grab its characteristics and make a new car
            Car* temp = new Car(i, j, v, m, d);
            //put new car into new array
            carray[i] = temp;
        }
    }
}
