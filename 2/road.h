#ifndef __ROAD_H__
#define __ROAD_H__
#include <list>
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
        int setdone(int newstate) { return isdone = newstate; }
        //default car constructor
        Car(int i, int j, int v, int m = 1, int d = 0) {x = i, y = j, vel = v;m = state;isdone = d; }
        //car destructor
        ~Car();
        //accelerate by 1
        void accel(int i = 1) { vel += i; }
        //allows printing
        friend ostream& operator<<(ostream& os, Car& c){ os<< "[" << c.velocity() << "]"; return os; };
        //get own position
        int geti() const{ return x; }
        int getj() const{ return y; }
        //set own position
        int seti(int i) { return x=i; }
        int setj(int j) { return y=j; }
    private:
        int isdone;
        int vel;
        int state;
        int x;
        int y;
};
//cucc my socc, binch
class Lane {
    public:
    //vector of sharedpointer of cars: default construcotr
       Lane(int l){ carray = new Car*[l]; len = l; }
       //destructor
       ~Lane(){ delete[] carray; }
       //copy constructor
       Lane(const Lane& l);

       Car** carray; //only call this when modifying
       //get lane size
       int size() const{ return len; }
       //get array of cars which makes up lane
       Car** carr() const { return carray; }
       //add new car to lane
       void addCar(Car* c);
       //allows printing
       friend ostream& operator<<(ostream& os, Lane& l){os<<"||"; for (int i= 0; i< l.size(); i++ ){os<<*(l.carray[i]);  }  ;os<<"||"<<endl;return os;};
    private:
       int len;
};

class Road {
    public:

        //CONSTRUCTORS AND DESTRUCTORS
        //road default constructor
        Road(int b){ larray = new Lane*[b]; wdth = b;cars = *(new list<Car*>());  }
        //road destructor
        ~Road(){ delete[] larray; }
        //copy constructor
        Road(const Road& r); 

        //DATA CONTAINERS
        //data member
        Lane** larray; //only call this when modifying
        list<Car*> cars;

        //ACCESSORS 
        //get road width
        int width() const{ return wdth; }
        //get array of lanes which makes up road
        Lane** larr() const{ return larray; }

        //add new lane to road
        void addLane(Lane* lpt, int i){
            larray[i] = &(*lpt);
        }
        //get neighbors
        int hasNeighbor(Car* car, int i);
        int hasLeft(Car* car){return hasNeighbor(car,-1);};
        int hasRight(Car* car){return hasNeighbor(car,1);};
        Car* getFront(Car* car){return getNeighbor(car,-1);};
        Car* getRight(Car* car){return getNeighbor(car,0);};
        Car* getLeft(Car* car){return getNeighbor(car,1);};
        Car* getNeighbor(Car* car, int i, int dir = 1);
        Car* getRightBack(Car* car){return getNeighbor(car, -1, -1);}
        Car* getLeftBack(Car* car){return getNeighbor(car,1, -1);}
        //road evolution methods
	void accelerate();
        void slow();
        void random();
        void motion();
        void merge();
        void clearDones();
        Road& next();
        //allows printing
        friend ostream& operator<<(ostream& os, Road& r){os<<"<--\n"; for (int i = 0; i < r.wdth; i++){os<<i<<": "<<r.larray[i]<<endl;}os<<"-->\n";return os;}

        
    private: 
        int wdth;
};

#endif
