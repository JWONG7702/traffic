#include <stdio.h>
// #include <time.h>

#include "road.h"

static int maxVel = 20;
static int maxDecel = maxVel/5;
static double phantomProbability = 0.2;
static int maxSearchRegion = 10;

//copy constructor for road
Road::Road(const Road& r) {
    wdth = r.wdth;
    cars = new list<Car*>;
    cars = r.cars;
    larray = new Lane*[wdth];

    for(int i=0;i<wdth;i++) {
        Lane* temp = new Lane(r.larr() + i*sizeof(Lane*));
        larray[i] = temp;
    }
}

//acclerate a car (default is by one)
void Road::accelerate() {
    for(Car* c : this->cars){
            if(c != 0){
                if(c->mode() == 1 && c->velocity() < maxVel){
                    c->accel();
                }
            }
    }
}

//slows a car down if it's about to crash into the thing in front of it, and if it can
void Road::slow(){
    for(Car* c : this->cars){
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
    for(Car* c : this->cars) {
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
    for (Car* c : this->cars) {
        int x = c->geti();
        int y = c->getj();
            if(c != 0){
                if(c->mode() == 1 && c->done() == 0){
                    if(c->getj() + (c->velocity()) >= this->larr()[x]->size()){
                        this->larray[x]->carray[y] = 0;
                        
                    } else {
                        this->larray[x]->carray[y+(c->velocity())] = c;
                        c->setdone(1);
                        this->larray[x]->carray[y] = 0;
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
    int whichWay = 0;
    for(Car* c : this->cars){
            if(c != 0){
                if(c->mode() == 1 && c->done() == 0){
                    if(this->hasRight(c)){
                        Car* d = this->getRight(c);
                        Car* f = this->getFront(c);
                        if(d == 0){
                            whichWay = 1;
                        }
                        if(whichWay == 0 && d != 0){
                            if(d->getj() + d->velocity() - c->getj() > f->getj() + f->velocity() - c->getj() )
                                whichWay = 1;
                        }
                    } else if(this->hasLeft(c)){
                        Car* e = this->getLeft(c);
                        if(e == 0){
                            whichWay = -1;
                        }
                        if(whichWay == 0 && e != 0){
                            if(e->getj() + e->velocity() - c->getj() > f->getj() + f->velocity() - c->getj() )
                                whichWay = -1;
                        }




                    }

                    if(whichWay == 1){
                        if(c->hasNeighbor(car, 2)){
                            Car* f = c->getNeighbor(car, 2);
                            Car* prev = c->getRightBack();
                            if(f != 0){
                                if(f->getj() == c->getj()){
                                    whichWay = 0;
                                } else if (prev != 0){
                                    if(prev->velocity() > c->getj() - prev->getj()){
                                        
                                    }
                                }

                            } else {

                            }

                        }
                    }
                }


            }
    }

}

//clears the done for all living cars (mode == 1)
void Road::clearDones(){
    for(Car* c : this->cars){
            if(c != 0){
                if(c->mode() == 1){
                    c->setdone(0);
                }
            }
    }
}

//checks if the lane is there
int Road::hasNeighbor(Car* car, int lane){
    int x = car->geti();
    if (x+lane >=0 && x+lane <= (this -> width())){
        return 0;
    } else {
        return 1;
    }
}

Car* Road::getNeighbor(Car* car, int lane){
    int x = car -> geti();
    int y = car -> getj();
    Car* nearest = 0;
    if (this->hasNeighbor(car, lane)){
        Lane* searchlane = this -> larr()[x+lane];
        for (int i = 0; i< maxSearchRegion;i++){
            if ( (nearest = searchlane -> carr()[y+i]) != 0){
                return nearest;
            }
        } 
        return nearest;//will be null if empty
    }
    return nearest;//never reached b/c always check if has neighbor before you run this method
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
