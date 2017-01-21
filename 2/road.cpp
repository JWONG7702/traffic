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
                if(c->velocity() > 1){
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

Road& Road::motion(){
    for(int i = 0; i < this->count; i++){
        for(int j = this->larr[i]->size-1; j >= 0; j++){
            Car* c = this->larr[i]->carr[j];
            if(c != 0){
                if(c->done() == 0){
                    if(j + (c->velocity()) >= this->larr[i]->size){
                        this->larr[i]->carr[j] = 0;
                        
                    } else {
                        this->larr[i]->carr[j+(c->velocity())] = c;
                        this->larr[i]->carr[j] = 0;
                    }
                }
            }
        }
    }
    return *this;
}

Road& Road::merge(){
    
}


Road& Road::next()
{
    this->accelerate();
    this->slow();
    this->random();
    this->motion();
    return *this;
}
