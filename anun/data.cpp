#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>    // std::transform
#include <list>
#include <chrono>
using namespace std;

const double id1[9]  = {7.5,5.3,11.1,10.0,9.1,8.8,12.6,15.4,11.9};
const double id2[7]  = {14.6,11.8,14.8,20.4,7.7,7.5,10.9};
const double scn[29] = {48.0,45.0,28.0,25.0,22.0,24.0,17.0,33.0,8.0,10.0,26.0,32.0,21.0,37.0,68.0,40.0,18.0,26.0,8.0,21.0,23.0,28.0,50.0,28.0,48.0,28.0,36.0,27.0,5.0};

//Entry intervals
const double intervalPre[57] = {11,2,1,1,10,9,20,2,19,1,28,5,15,22,28,4,1,2,5,3,1,10,2,12,19,24,18,1,1,1,28,7,24,5,4,17,3,5,35,1,2,1,16,1,20,9,5,0,1,5,29,7,2,1,1,16,1};
const double intervalNormal[46] = {9,1,1,2,1,2,11,30,24,55,8,3,16,1,22,7,2,12,2,58,15,6,12,9,31,17,3,20,79,12,10,1,2,2,12,2,1,1,11,13,8,2,17,21,19,3};
const double xr1[6] = {3.1,1.7,2.0,2.3,2.1,1.7}; //now useful
const double xr2[2] = {1.5,2.0}; //now useful
const double xr[8] = {3.1,1.7,2.0,2.3,2.1,1.7,1.5,2.0};



//cucc my socc, binch

int main() {
    /*
    vector<double> v1(intervalPre, intervalPre + sizeof(intervalPre)/sizeof(intervalPre[0]));
    double sum1 = std::accumulate(v1.begin(), v1.end(), 0.0);
    double mean1 = sum1 / v1.size();
    std::vector<double> diff1(v1.size());
    std::transform(v1.begin(), v1.end(), diff1.begin(), [mean1](double x) { return x - mean1; });
    double sq_sum1 = std::inner_product(diff1.begin(), diff1.end(), diff1.begin(), 0.0);
    double stdev1 = std::sqrt(sq_sum1 / (v1.size() - 1));
    printf("%d %d %6.4f %6.4f\n", 1, 1, mean1, stdev1);
    */

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_real_distribution<double> dist(0.0,0.999999);

    double delay = 0;
    double nfin = 0;
    double nstart = 0;
    double tstart = 0;
    double tfin = 0;
    list<double> qid1;
    list<double> qid2;
    list<double> qxr;

    for(double i=0;i<1000;i+=0.1) {
        if(delay < 0.05) {
            int ind = (int) 57*dist(gen);
            delay = intervalPre[ind];
            nstart += 1;
            tstart += i;
            int ind1 = (int) 9*dist(gen);
            int ind2 = (int) 7*dist(gen);
            if(dist(gen) < (1+qid2.size())/(2+qid2.size()+qid1.size())) qid1.push_back(intervalPre[ind1]);
            else qid2.push_back(intervalPre[ind2]);
        }

        if(!qid1.empty()) {
            if(qid1.front() < 0.05) {
                qid1.pop_front();
                int ind = (int) 8*dist(gen);
                qxr.push_back(xr[ind]);
            }
        }

        if(!qid2.empty()) {
            if(qid2.front() < 0.05) {
                qid2.pop_front();
                int ind = (int) 8*dist(gen);
                qxr.push_back(xr[ind]);
            }
        }

        if(!qxr.empty()) {
            if(qxr.front() < 0.05) {
                qxr.pop_front();
                nfin += 1;
                tfin += i;
            }
        }

        delay -= 0.1;
        if(!qid1.empty()) qid1.front() -= 0.1;
        if(!qid2.empty()) qid2.front() -= 0.1;
        if(!qxr.empty()) qxr.front() -= 0.1;
    }

    cout << tfin/nfin - tstart/nstart << endl;
}
