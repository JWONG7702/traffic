#ifndef __ROAD_H__
#define __ROAD_H__

#include <iostream>
#include <cstdio>
using namespace std;
class Car {
    public:
        int velocity() const{ return vel;}
        Car(int v){vel = v;}
        ~Car();
        void accel( int i) { vel += i;}
        friend ostream& operator<<(ostream& os, Car& c){os<< "[" << c.velocity() << "]"; return os;};
    private:
        int vel;
};
//cucc my socc, binch
class Lane {
    public:
    //vector of sharedpointer of cars
       Lane(int l){ carr = new Car*[l]; size = l;}
       ~Lane(){delete carr;}
       int size;
       Car** carr;
};

class Road {
    public:
        int count;
        Lane** larr;
        Road(int b){ larr = new Lane*[b]; count = b;}
        void addLane(Lane* lpt, int i){
            larr[i] = &(*lpt);
        }
	Road& next() { return *this; }
};

#endif
