//  rec_fun.cpp
//  STUDENT: YAW AMANKWAH
//  ID: ****3700
//  INTEGRITY STATEMENT:
//  “The work in this assignment is my own. Any outside sources have been properly cited.”

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
//#include <cmath>
#include "rec_fun.h"
using namespace std;

void triangle(ostream& outs, unsigned int m, unsigned int n) {
    assert(m <=n);
    if (m > n) return;
    if (m == n) {
        cout << string(m, '*') << endl;
        cout << string(m, '*') << endl;
    }
    else {
        cout << string(m, '*') << endl;
        triangle(cout, m+1, n);
        cout << string(m, '*') << endl;
    }
    }
    

void indented_sentences(size_t m, size_t n) {
    assert(m <=n);
    if (m > n) return;
    if (m == n) {
        cout << string (m, ' ') << "This was written by calling number " << m << "." << endl;
        cout << string (m, ' ') << "This was ALSO written by calling number " << m << "." << endl;
    }
    else {
        cout << string (m, ' ') << "This was written by calling number " << m << "." << endl;
        indented_sentences(m+1, n);
        cout << string (m, ' ') << "This was ALSO written by calling number " << m << "." << endl;
    }
}

void binary_print(ostream& outs, unsigned int n) {
    if (n == 0) {
        cout << 0; return;
    }
    else if (n == 1) {
        cout << 1; return;
    }
    else {
        binary_print(cout, n/2);
        cout << n%2;
    }
}
   

double power (double x, int n) {
    if (x==0) {
        assert(n >0);
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else if (n > 0) {
        if (n%2==1) {
        return x*power(x, n-1);
        }
        else return (power(x, n/2) * power(x, n/2));
    }
    else
        return 1/power(x, -n);
}




