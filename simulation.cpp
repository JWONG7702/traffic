
#include "road.h"
int main(){
    Car* c = new Car(3);
    c->accel(9);
    Lane* l = new Lane(2);
    l->carr[0] = c;
    l->carr[1] = c;
    
    for (int i = 0; i< 2; i++){
        cout << *(l->carr[i]) <<endl;
    }
}
//anun, pass it on
//anoon, pass it on
