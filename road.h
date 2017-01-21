#ifndef __ROAD_H__
#define __ROAD_H__

#include <iostream>
#include <cstdio>
using namespace std;
class Car {
    public:
        int velocity;
        Car(int v){velocity = v;}
        ~Car();
        void accel( int i) { velocity += i;}
        friend ostream& operator<<(ostream& os, Car& c){os<< "[" << c.velocity << "]"; return os;};
};
//cucc my socc, binch
class Lane {
    public:
    //vector of sharedpointer of cars
       int size;
       Car** carr;
       Lane(int l){ carr = new Car*[l]; size = l;}
};

class Road {
    public:
        int count;
        Lane** larr;
        Road(int b){ larr = new Lane*[b]; count = b;}
        void addLane(Lane* lpt, int i){
            larr[i] = &(*lpt);
        }
};

#endif
