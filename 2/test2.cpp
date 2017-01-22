#include "road.h"
#include <iostream>
#include <list>
using namespace std;
int main (){
    cout << "woeifn" << endl;
    Car* c1 = new Car(0,0,3);
    c1->accel(9);
    Car* c2 = new Car(0,0,3);
    cout << *c2 << *c1 << endl;
 
    Lane* l1 = new Lane(20);
    l1->carr()[0] = c1;
    l1->carr()[10] = c2;
    Lane* l2 = new Lane(10);
    cout << *l1 << endl;
    Lane** arroflanes = new Lane*();
    arroflanes[0] = l1;
    arroflanes[1] = l2;
    Road *r = new Road(arroflanes, 2);
    cout << *r <<endl;    
    
    list<Road>* simulation = new list<Road>();
    for (int i = 0; i < 10; i++){
        simulation->push_front(*r);
        r = &(r->next());
    } 
    for (auto it = simulation->begin(); it != simulation->end(); it++){
        cout << *it<< endl;
    } 
    
}
