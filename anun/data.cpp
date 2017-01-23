#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>    // std::transform
#include <vector>
using namespace std;

const double id1[9]  = {7.5,5.3,11.1,10.0,9.1,8.8,12.6,15.4,11.9};
const double id2[7]  = {14.6,11.8,14.8,20.4,7.7,7.5,10.9};
const double scn[29] = {48.0,45.0,28.0,25.0,22.0,24.0,17.0,33.0,8.0,10.0,26.0,32.0,21.0,37.0,68.0,40.0,18.0,26.0,8.0,21.0,23.0,28.0,50.0,28.0,48.0,28.0,36.0,27.0,5.0};
const double xr1[11] = {2.5,5.6,7.3,9.3,20.1,22.4,24.5,41.2,67.1,68.8,77.9}; //not useful
const double xr2[4]  = {0.0,1.5,3.5,11.0}; //not useful


const double intervalPre[57] = {11,2,1,1,10,9,20,2,19,1,28,5,15,22,28,4,1,2,5,3,1,10,2,12,19,24,18,1,1,1,28,7,24,5,4,17,3,5,35,1,2,1,16,1,20,9,5,0,1,5,29,7,2,1,1,16,1};
const double intervalNormal[46] = {9,1,1,2,1,2,11,30,24,55,8,3,16,1,22,7,2,12,2,58,15,6,12,9,31,17,3,20,79,12,10,1,2,2,12,2,1,1,11,13,8,2,17,21,19,3};
//cucc my socc, binch

int main() {
    vector<double> v1(intervalPre, intervalPre + sizeof(intervalPre)/sizeof(intervalPre[0]));
    double sum1 = std::accumulate(v1.begin(), v1.end(), 0.0);
    double mean1 = sum1 / v1.size();
    std::vector<double> diff1(v1.size());
    std::transform(v1.begin(), v1.end(), diff1.begin(), [mean1](double x) { return x - mean1; });
    double sq_sum1 = std::inner_product(diff1.begin(), diff1.end(), diff1.begin(), 0.0);
    double stdev1 = std::sqrt(sq_sum1 / (v1.size() - 1));
    printf("%d %d %6.4f %6.4f\n", 1, 1, mean1, stdev1);

} 
