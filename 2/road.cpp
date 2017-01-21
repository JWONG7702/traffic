#include <stdio.h>
// #include <time.h>

#include "road.h"

static int maxVel = 20;
static int maxDecel = maxVel/5;
static double phantomProbability = 0.2;
static int maxSearchRegion = 10;
void Road::accelerate(){
    for(Car* c : cars){
            if(c != 0){
                if(c->mode() == 1 && c->velocity() < maxVel){
                    c->accel();
                }
            }
    }
}

//slows a car down if it's about to crash into the thing in front of it, and if it can
void Road::slow(){
    for(Car* c : cars){
            if(c != 0){
                if(c->mode() == 1 && -c->getj() + this->getFront(c)->getj() + this->getFront(c)->velocity() - c->velocity() < 0){
                    int accelAmount = (-c->getj() + this->getFront(c)->getj() + this->getFront(c)->velocity() - c->velocity() - 1 < -maxDecel) ? 0 : -c->getj() + this->getFront(c)->getj() + this->getFront(c)->velocity() - c->velocity();
                    c->accel(accelAmount); 
                }
            }
    }
}

//randomly changes the velocity of some cars to be lower, based on a phantomProbability
void Road::random(){
    for(Car* c : cars) {
            // srand(time(NULL));
            if(c != 0) {
                if(c->mode() == 1 && c->velocity() > 1){
                    double r = ((double) rand() / (RAND_MAX));
                    if(r < phantomProbability){
                        c->accel(-1);
                    }
                }
            }
    }
}

//for all the cars that haven't done their action (if they haven't changed lanes/merged) are just moved forward by their velocity
void Road::motion(){
    for (Car* c : cars) {
            if(c != 0){
                if(c->mode() == 1 && c->done() == 0){
                    if(c->getj + (c->velocity()) >= this->larr[i]->size){
                        this->larr[i]->carr[j] = 0;
                        
                    } else {
                        this->larr[i]->carr[j+(c->velocity())] = c;
                        this->larr[i]->carr[j+(c->velocity())]->setdone(1);
                        this->larr[i]->carr[j] = 0;
                    }
                }
            }
    }
}

//handles merges and lane changes
/*
 Car checks maximum speed it can achieve on it's current position (x, lane) and adjacent lane (x, lane+1).
 If the potential maximal speed on lane+1 is higher it checks safe conditions:
 There is no car car on (x, lane+2) to avoid collision caused by two parallel cars changing lane to lane+1.
 Distance to previous car on lane+1 is greater that it's speed to avoid emergency braking of previous car.
 Change lane with probability P.

 */
void Road::merge(){
    for(Car* c : car){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->mode() == 1 && c->done() == 0){
                    
                }
            }
    }

}

//clears the done for all living cars (mode == 1)
void Road::clearDones(){
    for(Car* c : cars){
            if(c != 0){
                if(c->mode() == 1){
                    c->setdone(0);
                }
            }
    }
}

Car* Road::getNeighbor(Car* car, int lane){
    x = car.geti();
    y = car.getj();
    Car* nearest = 0;
    if (j+lane >=0 && j+lane <= (this -> width()){
        Lane* searchlane = this -> larr()[j+lane]
        for (int i = 0; i< maxSearchRegion;i++){
            if ( (nearest = searchlane -> carr()[x+i]) != 0){
                return nearest;
            }
        } 
        return nearest;
    }
    return ERROR;//error
}
//advances the entire simulation (the road) forward one time step
Road& Road::next()
{
    Road *r = new Road(this);
    r->accelerate();
    r->slow();
    r->random();
    r->merge();
    r->accelerate();
    r->slow();
    r->random();
    r->motion();
    r->clearDones();
    return *r;
}
