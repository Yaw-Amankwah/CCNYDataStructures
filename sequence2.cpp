
// STUDENT: YAW AMANKWAH
// ID: ****3700
// INTEGRITY POLICY: The work in this assignment is my own. Any outside sources have been properly cited.
// FILE: sequence2.cpp
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
// INVARIANTS - Borrowed from DATA STRUCTURES AND OTHER OBJECTS USING C++, MAIN & SAVITCH, 4TH EDITION, PAGE 127.
// 1. The number of items in the sequence is stored in the member variable "used".
// 2. For an empty sequence, we do not care what is stored in any of "data"; for a non-empty sequence, the items in the bag are stored in "data[0]" through "data[used-1]", and we don't care what is stored in the rest of "data".
// 3. If there is a current item, then it lies in "data[current_index]"; if there is no current item, then "current_index" equals "used".

#include "sequence2.hpp"
#include <cassert>
#include <cstdlib>


using namespace std;

namespace main_savitch_4

{
    // TYPEDEFS and MEMBER CONSTANTS
    typedef double value_type;
    typedef size_t size_type; //typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30}; //
    // CONSTRUCTOR
sequence::sequence(size_type initial_capacity) { //O(1)
    data = new value_type[initial_capacity];
    complete_capacity = initial_capacity;
    used = 0;
    current_index = 0; 
}

sequence::sequence(const sequence& source) { //O(n)
    data = new value_type[source.complete_capacity];
    complete_capacity = source.complete_capacity;
    used = source.used;
    current_index = source.current_index;
    for (size_t i = 0; i < used; i++) {
        data[i] = source.data[i];
    }
}

    // MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) { //O(1)
    current_index = 0;
}

void sequence::advance() { //O(1)
    assert(is_item());
    current_index++;
}

void sequence::insert(const value_type& entry) { //O(n)
    if (used == complete_capacity) {
        resize(used+1);}
    if (!(is_item())) {
        for (size_t i = used; i > 0; i--) {
                  data[i] = data[i-1];
              }
        data[0] = entry; current_index = 0;
    }
    else {
        for (size_t i = used; i > current_index; i--) {
            data[i] = data[i-1];
        } data[current_index] = entry;
    } used++;
}


void sequence::attach(const value_type& entry) { //O(n)
    if (used == complete_capacity) {
    resize(used+1);}
    if (!(is_item())) {
        data[used] = entry;
        current_index = used;
    }
    else {
        for (size_t i = used; i > current_index; i--) {
            data[i] = data[i-1];
        }
        data[current_index+1] = entry;
        current_index++;
    }
    used++;
}

void sequence::remove_current( ) { //O(n)
    assert (is_item());
    for (size_t i = current_index; i < used - 1; i++) {
        data[i] = data[i+1];
    }
    used--;
}

void sequence::resize(size_type new_capacity) { //O(n)
    value_type *temp; size_t used2, current_index2;
    used2 = used;
    current_index2 = current_index;
    if (new_capacity < used) {return; }
    else  {
        temp = new value_type[new_capacity];
    
    for (size_t i = 0; i < used; i++) {
        temp[i] = data[i];
    }
        
        delete [] data;
        data = temp;
        complete_capacity = new_capacity;
        used = used2;
        current_index = current_index2;
    }
}

void sequence::operator=(const sequence& source) {//O(n)
    if((used == source.used) && (data == source.data) && (complete_capacity == source.complete_capacity) && (current_index == source.current_index)) {return; }
    else {
            value_type *temp = new value_type[source.complete_capacity];
            delete [] data;
            data = temp;
            complete_capacity = source.complete_capacity;
        }
        used = source.used;
        current_index = source.current_index;
       for (size_t i = 0; i < used; i++) {
           data[i] = source.data[i];
       }
    }

    // CONSTANT MEMBER FUNCTIONS

value_type sequence::operator[](size_type index) const { //O(1)
    return data[index];
}

bool sequence::is_item( ) const { //O(1)
    if (current_index < used) { return  true;}
    else return false;
}
value_type sequence::current( ) const { //O(1)
    assert(is_item());
    return data[current_index];
}

    // EXTRA CREDIT

sequence sequence:: operator+ (const sequence& y) {//O(n)
    size_t capacity = used + y.used;
    sequence sum(*data);
    sum.resize(capacity);
    for (size_t i = 0; i < y.used; i++) {
        sum.data[used+i] = y.data[i];
    }
    sum.current_index = capacity - 1;
    sum.complete_capacity = capacity;
    sum.used = capacity;
    return sum;
}

sequence sequence::operator+= (const sequence& y) {//O(n)
    resize(used + y.used);
    for (size_t i = 0; i < y.used; i++) {
        data[used+i] = y.data[i];
    }
    used+=y.used;
    current_index+=y.used;
    complete_capacity = used;
    return *data;
}
}

