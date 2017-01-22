#include "road.h"
#include <chrono>
#include <random>

int main() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_real_distribution<double> dist(0.0,1.0);

    Car* c1 = new Car(0,0,3);
    c1->accel(9);
    Car* c2 = new Car(0,0,3);

    Lane* l1 = new Lane(200);
    l1->carr()[0] = c1;
    l1->carr()[100] = c2;
    Lane* l2 = new Lane(100);
    
    Road* r = new Road(2);
    r->larr()[0] = l1;
    r->larr()[1] = l2;

    for(int i = 0; i<r->width(); i++) {
	for(int j=0; j<r->larr()[i]->size(); j++) {
            if(Car* it = r->larr()[i]->carr()[j]) cout << it->velocity()<<endl;
        }
    }
}
//anun, pass it on
//anoon, pass it on
