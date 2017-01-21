#ifndef __ROAD_H__
#define __ROAD_H__

#include <iostream>
#include <cstdio>
using namespace std;
class Car {
    public:
        int velocity() const{ return vel;}
        int mode() const{ return state;}
        int done() const{ return isdone;}
        int setdone(int newstate) {isdone = newstate;}
        Car(int v, int m = 1, int d = 0){vel = v;m = state;isdone = d;}
        ~Car();
        void accel( int i = 1) { vel += i;}
        friend ostream& operator<<(ostream& os, Car& c){os<< "[" << c.velocity() << "]"; return os;};
    private:
        int isdone;
        int vel;
        int state;
};
//cucc my socc, binch
class Lane {
    public:
    //vector of sharedpointer of cars
       Lane(int l){ carray = new Car*[l]; len = l;}
       ~Lane(){delete[] carray;}
       int size() const{return len;}
       Car** carr() const {return carray;}
       void addCar(Car* c){
           carray[0] = c;
       }
       friend ostream& operator<<(ostream& os, Lane& l);
    private:
       int len;
       Car** carray;
};

class Road {
    public:
        
        int length() const{return len;}
        Lane** larr() const{return larray;}
        Road(int b){ larray = new Lane*[b]; len = b;}
        ~Road(){ delete[] larray;}
        void addLane(Lane* lpt, int i){
            larray[i] = &(*lpt);
        }
	Road& accelerate();
        Road& slow();
        Road& random();
        Road& motion();
        Road& next();
        friend ostream& operator<<(ostream& os, Road& r);
    private: 
        int len;
        Lane** larray;
};

#endif
