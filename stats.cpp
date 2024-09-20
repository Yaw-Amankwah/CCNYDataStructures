
// Provided by:   ____________(NAME: Yaw Amankwah / ID: ****3700)__________
// Email Address: ____________(yamankw000@citymail.cuny.edu)________
// ID: _______________________(3700)________________________________
// INTEGRITY POLICY:   “The work in this assignment is my own. Any outside sources have been properly cited.”
// FILE: stats.cpp
#include "stats.h"
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

namespace main_savitch_2C {

        // CONSTRUCTOR
statistician::statistician( ) {
    count = 0; total = 0;
}
        // MODIFICATION MEMBER FUNCTIONS
void statistician::next(double r) {
    count++; total += r;
    if (count==1) {
        tinyest = r;
        largest = r;
    }
    else {
        if (r < tinyest) {tinyest = r;}
        if (r > largest) {largest = r;}
    }
}
void statistician::reset( ) {
    count = 0; total = 0; tinyest = 0; largest = 0;
}
        // CONSTANT MEMBER FUNCTIONS
double statistician::mean( ) const {
    assert (count > 0);//Precondition
    return (sum()/length());
}
double statistician::minimum( ) const {
    assert(count > 0);//Precondition
    return tinyest;
}
double statistician::maximum( ) const {
    assert(count > 0);//Precondition
    return largest;
}
        // FRIEND FUNCTIONS
statistician operator +(const statistician& s1, const statistician& s2) {
     statistician added;
     added.count = s1.length() + s2.length();
     added.total = s1.sum() + s2.sum();
     added.tinyest = min (s1.tinyest, s2.tinyest);
     added.largest = max (s1.largest, s2.largest);
 return added;
 }

statistician operator * (double scale, const statistician& s) {
    statistician multiplied;
    multiplied.count = s.count;
    multiplied.total = scale * s.total;
    multiplied.tinyest = scale * s.tinyest;
    multiplied.largest = scale * s.largest;
    return multiplied;
}


    // NON-MEMBER functions for the statistician class
bool operator ==(const statistician& s1, const statistician& s2) {
    if ((s1.length() == 0) && (s2.length() == 0)) {return true;}
    else if ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.mean() == s2.mean()) && (s1.maximum() == s2.maximum()) && (s1.minimum() == s2.minimum()))
            {return true;}
    else return false;
}
}
