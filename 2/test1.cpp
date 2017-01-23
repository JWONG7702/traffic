#include "road.h"
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <numeric>

static double density = 0.2;

int main() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_real_distribution<double> dist(0.0,1.0);

    Lane* l = new Lane(2000);

    Road* r = new Road(1);
    r->addLane(l, 0);

    for(int i=0;i<1000;i++) {
        if(dist(gen) > density) r->addCar(0);
        r = &(r->next());
    }

    vector<double> vels;

    for(int i=0;i<1000;i++) {
	if(dist(gen) > density) r->addCar(0);
        r = &(r->next());
        for(Car* c : r->cars) {
            vels.push_back((double) c->velocity());
        }
    }
    
    cout << vels.size() << endl;

    for(unsigned i=0; i<vels.size(); ++i) cout << '[' << vels[i] << ']';

    double result = accumulate(vels.begin(), vels.end(), 0.0)/vels.size();
    cout << result << endl;
}
//anun, pass it on
//anoon, pass it on
