
// STUDENT: YAW AMANKWAH
// ID: ****3700
// INTEGRITY POLICY: “The work in this assignment is my own. Any outside sources have been properly cited.”
// FILE: sequence.cpp
// CLASS PROVIDED: sequence (part of the namespace main_savitch_3)
// INVARIANTS - Borrowed from DATA STRUCTURES AND OTHER OBJECTS USING C++, MAIN & SAVITCH, 4TH EDITION, PAGE 127.
// 1. The number of items in the sequence is stored in the member variable "used".
// 2. For an empty sequence, we do not care what is stored in any of "data"; for a non-empty sequence, the items in the bag are stored in "data[0]" through "data[used-1]", and we don't care what is stored in the rest of "data".
// 3. If there is a current item, then it lies in "data[current_index]"; if there is no current item, then "current_index" equals "used".

#include <cassert>
#include <cstdlib>  // Provides size_t
#include "sequence.hpp"
using namespace std;

namespace main_savitch_3
{

        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        const sequence::size_type sequence::CAPACITY;
        // CONSTRUCTOR
sequence::sequence( ) {
    used = 0;
    current_index = 0;
}
        // MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) {
    if (used > 0) { current_index = 0;}
    else current_index = used;
}

void sequence::advance( ) {
    assert (is_item());
    current_index++;
}

void sequence::insert(const value_type& entry) {
    assert (size() < CAPACITY);   //to be done later
    if (!(is_item())) {
        for (int i = int(used); i > 0; i--) {
                  data[i] = data[i-1];
              }
        data[0] = entry; current_index = 0;
    }
    else {
        for (int i = int(used); i > current_index; i--) {
            data[i] = data[i-1];
        } data[current_index] = entry;
    } used++;
}

void sequence::attach(const value_type& entry) {
    assert (size() < CAPACITY);
    if (!(is_item())) {
        data[used] = entry;
        current_index = used;
    }
    else {
        for (int i = int(used); i > current_index; i--) {
            data[i] = data[i-1];
        }
        data[current_index+1] = entry;
        current_index++;
    }
    used++;
}

void sequence::remove_current( ) {
    assert (is_item());
    for (int i = int(current_index); i < used - 1; i++) {
        data[i] = data[i+1];
    }
    used--;
}
        // CONSTANT MEMBER FUNCTIONS
bool sequence::is_item( ) const {
    if (current_index < used) { return  true;}
    else return false;
}

value_type sequence::current( ) const {
    assert(is_item());
    return data[current_index];
}

}




