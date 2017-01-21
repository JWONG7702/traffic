#include <cstdio>
#include <ctime>

#include "road.h"

static int maxVel = 20;
static int maxDecel = maxVel/5;
static double phantomProbability = 0.2;

Road& Road::accelerate(){
    for(int i = 0; i < this->length(); i++){
        for(int j = 0; j < this->larr()[i]->size(); j++){
            Car* c = this->larr()[i]->carr()[j];
            if(c != 0){
                if(c->mode() == 1 && c->velocity() < maxVel){
                    c->accel();
                }
            }
        }
    }
    return *this;
}

//slows a car down if it's about to crash into the thing in front of it, and if it can
Road& Road::slow(){
    for(int i = 0; i < this->length(); i++){
        for(int j = 0; j < this->larr()[i]->size(); j++){
            Car* c = this->larr()[i]->carr()[j];
            if(c != 0){
                if(c->mode() == 1 && c->getFrontPos() + c->getFrontVel() - c->velocity() < 0){
                    int accelAmount = (c->getFrontPos() + c->getFrontVel() - c->velocity() - 1 < -maxDecel) ? 0 : c->getFrontPos() + c->getFrontVel() - c->velocity() - 1;
                    c->accel(accelAmount); 
                }
            }
        }
    }
    return *this;
    
}

//randomly changes the velocity of some cars to be lower, based on a phantomProbability
Road& Road::random(){
    for(int i = 0; i < this->count; i++){
        for(int j = 0; j < this->larr[i]->size; j++){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->mode() == 1 && c->velocity() > 1){
                    double r = ((double) rand() / (RAND_MAX));
                    if(r < phantomProbability){
                        c->accel(-1);
                    }
                }
            }
        }
    }
    return *this;
}

//for all the cars that haven't done their action (if they haven't changed lanes/merged) are just moved forward by their velocity
Road& Road::motion(){
    for(int i = 0; i < this->count; i++){
        for(int j = this->larr[i]->size-1; j >= 0; j++){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->mode() == 1 && c->done() == 0){
                    if(j + (c->velocity()) >= this->larr[i]->size){
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
    return *this;
}

//handles merges and lane changes
/*
 Car checks maximum speed it can achieve on it's current position (x, lane) and adjacent lane (x, lane+1).
 If the potential maximal speed on lane+1 is higher it checks safe conditions:
 There is no car car on (x, lane+2) to avoid collision caused by two parallel cars changing lane to lane+1.
 Distance to previous car on lane+1 is greater that it's speed to avoid emergency braking of previous car.
 Change lane with probability P.

 */
Road& Road::merge(){
    
}

//clears the done for all living cars (mode == 1)
Road& Road::clearDones(){
    for(int i = 0; i < this->count; i++){
        for(int j = this->larr[i]->size-1; j >= 0; j++){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->mode() == 1){
                    c->setdone(0);
                }
            }
        }
    }
}


//advances the entire simulation (the road) forward one time step
Road& Road::next()
{
    this->accelerate();
    this->slow();
    this->random();
    this->merge();
    this->accelerate();
    this->slow();
    this->random();
    this->motion();
    this->clearDones();
    return *this;
}
