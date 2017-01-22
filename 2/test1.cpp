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
    cout << "random is easy" << endl;
    Lane* l = new Lane(2000);
    cout << "lane construction successful" << endl;
    Road* r = new Road(1);
    r->larr()[0] = l;
    l->i = 0;
    cout << "road construction and addition successful" << endl;
    for(int i=0;i<1000;i++) {
        cout << "entered loop" << endl;
        if(dist(gen) > density) l->addCar(0);
        cout << "added car" << endl;
        r->next();
        cout << "went next" << endl;
    }
    cout << "preliminary run successful" << endl;
    vector<double> vels;

    for(int i=0;i<1000;i++) {
	if(dist(gen) > density) l->addCar(0);
        r->next();
        for(Car* c : r->cars) {
            if(c->getj() > 1000) vels.push_back((double) c->velocity());
        }
    }
    cout << "we should finish if here" << endl;
    double result = accumulate(vels.begin(), vels.end(), 0.0)/vels.size();
    cout << result << endl;
}
//anun, pass it on
//anoon, pass it on
