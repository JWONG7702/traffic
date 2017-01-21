#ifndef __ROAD_H__
#define __ROAD_H__

#include <iostream>
#include <cstdio>
using namespace std;
class Car {
    public:
        //get car velocity
        int velocity() const{ return vel; }
        //get car mode
        int mode() const{ return state; }
        //get car isdone status
        int done() const{ return isdone; }
        //set car isdone status
        int setdone(int newstate) {isdone = newstate; }
        //default car constructor
        Car(int v, int m = 1, int d = 0){ vel = v;m = state;isdone = d;front=0;back=0 }
        //car destructor
        ~Car();
        //accelerate by 1
        void accel( int i = 1) { vel += i; }
        //allows printing
        friend ostream& operator<<(ostream& os, Car& c){ os<< "[" << c.velocity() << "]"; return os; };
        //get position of car in front
        int getFrontPos(Car* c) const{ return this->front->pos; }
        //get velocity of car in front
        int getFrontVel(Car* c) const{ return this->front->vel; }
        //set pointer to car in front
        void setFront(Car* c) const{ this.front = c; }
        //set pointer to car in back
        void setBack(Car* c) const{ this.back = c; }
    private:
        int isdone;
        int vel;
        int state;
        int pos;
        Car* front;
        Car* back;
};
//cucc my socc, binch
class Lane {
    public:
    //vector of sharedpointer of cars: default construcotr
       Lane(int l){ carray = new Car*[l]; len = l; }
       //destructor
       ~Lane(){ delete[] carray; }
       //get lane size
       int size() const{ return len; }
       //get array of cars which makes up lane
       Car** carr() const { return carray; }
       //add new car to lane
       void addCar(Car* c);
       //allows printing
       friend ostream& operator<<(ostream& os, Lane& l);
    private:
       int len;
       Car** carray;
};

class Road {
    public:
        //get road width
        int width() const{ return wdth; }
        //get array of lanes which makes up road
        Lane** larr() const{ return larray; }
        //road default constructor
        Road(int b){ larray = new Lane*[b]; wdth = b; }
        //road destructor
        ~Road(){ delete[] larray; }
        //add new lane to road
        void addLane(Lane* lpt, int i){
            larray[i] = &(*lpt);
        }
        //road evolution methods
	Road& accelerate();
        Road& slow();
        Road& random();
        Road& motion();
        Road& next();
        //allows printing
        friend ostream& operator<<(ostream& os, Road& r);
    private: 
        int wdth;
        Lane** larray;
};

#endif
