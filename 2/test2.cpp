#include "road.h"
#include <iostream>
using namespace std;
int main (){
    cout << "woeifn" << endl;
    Car* c1 = new Car(0,0,3);
    c1->accel(9);
    Car* c2 = new Car(0,0,3);
    cout << *c2 << *c1 << endl;
 
    Lane* l1 = new Lane(200);
    l1->carr()[0] = c1;
    l1->carr()[100] = c2;
    Lane* l2 = new Lane(100);
    cout << *l1 << endl;
    Lane** arroflanes = new Lane*();
    arroflanes[0] = l1;
    arroflanes[1] = l2;
    Road *r = new Road(arroflanes, 2);
    Road street = new Road(*r);
    cout << *r <<endl;    


}
