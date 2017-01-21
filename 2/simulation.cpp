#include "road.h"

int main(){
    Car* c1 = new Car(3);
    c1->accel(9);
    Car* c2 = new Car(3);

    Lane* l1 = new Lane(200);
    l1->carr()[0] = c1;
    l1->carr()[100] = c2;
    Lane* l2 = new Lane(100);
    
    Road* r = new Road(2);
    r->larr[0] = l1;
    r->larr[1] = l2;

    for(int i = 0; i<r->length(); i++) {
	for(int j=0; j<r->larr[i]->size(); j++) {
            if(Car* it = r->larr[i]->carr()[j]) cout << it->velocity()<<endl;
        }
    }
}
//anun, pass it on
//anoon, pass it on
