#include <cstdio>

#include "road.h"

static int maxVel = 20;
static int maxDecel = maxVel/5;
static int phantomProbability = 2;

Road& Road::accelerate(){
    for(int i = 0; i < this->length(); i++){
        for(int j = 0; j < this->larr()[i]->size(); j++){
            Car* c = this->larr()[i]->carr()[j];
            if(c != 0){
                if(c->velocity() < maxVel){
                    c->accel();
                }
            }
        }
    }
    return *this;
}

Road& Road::slow(){
    for(int i = 0; i < this->length(); i++){
        for(int j = 0; j < this->larr()[i]->size(); j++){
            Car* c = this->larr()[i]->carr()[j];
            if(c != 0){
                if(c->getFrontPos() + c->getFrontVel() - c->velocity() < 0){
                    int accelAmount = (c->getFrontPos() + c->getFrontVel() - c->velocity() - 1 < -maxDecel) ? 0 : c->getFrontPos() + c->getFrontVel() - c->velocity() - 1;
                    c->accel(accelAmount); 
                }
            }
        }
    }
    return *this;
    
}

Road& Road::random(){
    for(int i = 0; i < this->count; i++){
        for(int j = 0; j < this->larr[i]->size; j++){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->velocity() < maxVel){
                    c->accel();
                }
            }
        }
    }
    return *this;
}

Road& Road::motion(){
    return *this;
}


Road& Road::next()
{
    this->accelerate();
    this->slow();
    this->random();
    this->motion();
    return *this;
}
