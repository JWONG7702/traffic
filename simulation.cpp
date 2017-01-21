#include "road.h"
#include <cstdio>
#include <iostream>
using namespace std;
class Car {
    public:
        int velocity;
        Car(int v){velocity = v;}
        ~Car();
        void accel( int i) { velocity += i;}
        friend ostream& operator<<(ostream& os, Car& c){os<< "[" << c.velocity << "]"; return os;};
};
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

int main(){
    Car* c = new Car(3);
    c->accel(9);
    Lane* l = new Lane(2);
    l->carr[0] = c;
    l->carr[1] = c;
    
    for (int i = 0; i< 2; i++){
        cout << l->carr[i]->velocity<<endl;
    }
}
//anun, pass it on
//anoon, pass it on
