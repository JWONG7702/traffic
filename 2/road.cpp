#include <cstdio>

#include "road.h"

static int maxVel = 20;

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
                if(c->velocity() < maxVel){
                    c->accel(); //PUSH MY SHIT
                }
            }
        }
    }
    return *this;
    
}

Road& Road::random(){
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
