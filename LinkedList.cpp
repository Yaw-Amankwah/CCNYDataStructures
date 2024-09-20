//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Yaw Amankwah on 3/15/21.
//  Copyright © 2021 Yaw Amankwah. All rights reserved.

//  STUDENT: YAW AMANKWAH
//  ID: ****3700
//  INTEGRITY STATEMENT: “The work in this assignment is my own. Any outside sources have been properly cited.”
//
//  INVARIANTS OF SEQUENCE CLASS USING LINKED LISTS
//  1. The items in the sequence are stored in node objects using a singly linked list.
//  2. The first item in the sequence is stored in the node pointed to by the member variable "head_ptr."
//  3. The last item in the sequence is stored in the node pointed to by the member variable "tail_ptr."
//  4. The total number of items in the sequence is stored in the member variable "num_nodes."
//  5. The current item in the sequence is stored in the node pointed to by the member variable "cursor."
//  6. The item before current item in the sequence is stored in the node pointed to by the member variable "precursor."

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include "Node.hpp"
#include "LinkedList.hpp"
using namespace std;

namespace main_savitch_5 {

sequence::sequence( ) { //  O(1) Time complexity...Same as dynamic array
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    num_nodes = 0;
}

sequence::sequence(const sequence& source) { // O(n) Time complexity...Same as dynamic array
    
    if (this == &source) {return;}
    if (source.head_ptr == NULL) {
        num_nodes = 0;
        cursor = precursor = head_ptr = tail_ptr = NULL;
        return;
    }
    if (source.cursor == NULL) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        num_nodes = source.num_nodes;
        precursor = NULL;
        cursor = NULL;
        }
    else if (source.cursor == source.head_ptr) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        precursor = NULL;
        cursor = this->head_ptr;
        num_nodes = source.num_nodes;
        }
    else {
        head_ptr = tail_ptr = NULL;
        node *copy_ptr = source.head_ptr;
        head_ptr = new node(copy_ptr->data());
        cursor = tail_ptr = head_ptr;
        while (copy_ptr->link()!= NULL) {
            copy_ptr = copy_ptr->link();
            tail_ptr = new node (copy_ptr->data());
            if (copy_ptr == source.precursor) {
                precursor = tail_ptr;
            }
            cursor->set_link(tail_ptr);
            cursor = tail_ptr;
        }
        cursor = precursor->link();
        }
        num_nodes = source.num_nodes;
}
     


sequence::~sequence( ) {//  O(1) Time complexity...Same as dynamic array
    list_clear(head_ptr);
    num_nodes = 0;
}
// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ) {// O(1) Time complexity...Same as dynamic array
    precursor = NULL;
    cursor = head_ptr;
}

void sequence::advance( ) {//   O(1) Time complexity...Same as dynamic array
    assert(is_item());
    precursor = cursor;
    cursor = cursor->link();
}

void sequence::insert(const value_type& entry) {// O(1) Time complexity...Better than dynamic array, which has O(n) Time complexity
     if (cursor == NULL) {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
        }
    else if (cursor == head_ptr) {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
    }
    else {
        list_insert(precursor, entry);
        cursor = precursor->link();
    }
    num_nodes++;
}

void sequence::attach(const value_type& entry) {//  O(1) Time complexity...Better than dynamic array, which has O(n) Time complexity
    if (head_ptr == NULL) {
        list_head_insert(head_ptr, entry);
        tail_ptr = head_ptr;
        cursor = head_ptr;
        precursor = NULL;
    }
    else if (cursor == NULL) {
        cursor = tail_ptr;
        tail_ptr = new node(entry);
        precursor = cursor;
        cursor->set_link(tail_ptr);
        cursor = tail_ptr;
    }
    else if (cursor == tail_ptr) {
        tail_ptr = new node(entry);
        precursor = cursor;
        cursor->set_link(tail_ptr);
        cursor = tail_ptr;
    }
    else {
        node *attach_ptr = new node (entry, cursor->link());
        cursor->set_link(attach_ptr);
        precursor = cursor;
        cursor = attach_ptr;
    }
    num_nodes++;
}

void sequence::remove_current( ) {//    O(1) Time complexity...Better than dynamic array, which has O(n) Time complexity
    assert(is_item());
    if (cursor == head_ptr) {
        list_head_remove(head_ptr);
        cursor = head_ptr;
        precursor = NULL;
    }
    else {
        if (cursor == tail_ptr) {tail_ptr = precursor;
        }
        list_remove(precursor);
        cursor = precursor->link();
    }
    num_nodes--;
}

void sequence::operator =(const sequence& source) {//   O(n) Time complexity...Same as dynamic array
    if (this == &source) { return;}
    list_clear(head_ptr);
    num_nodes = 0;
    
    if (source.head_ptr == NULL) {
        num_nodes = 0;
        cursor = precursor = head_ptr = tail_ptr = NULL;
        return;
    }
    else if (source.cursor == NULL) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        num_nodes = source.num_nodes;
        precursor = NULL;
        cursor = NULL;
    }
    else if (source.cursor == source.head_ptr) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        precursor = NULL;
        cursor = this->head_ptr;
        num_nodes = source.num_nodes;
      }
      else {
          head_ptr = tail_ptr = NULL;
          node *copy_ptr = source.head_ptr;
          head_ptr = new node(copy_ptr->data());
          cursor = tail_ptr = head_ptr;
          while (copy_ptr->link()!= NULL) {
              copy_ptr = copy_ptr->link();
              tail_ptr = new node (copy_ptr->data());
              if (copy_ptr == source.precursor) {
                  precursor = tail_ptr;
              }
              cursor->set_link(tail_ptr);
              cursor = tail_ptr;
          }
          cursor = precursor->link();
      }
        num_nodes = source.num_nodes;
}
   
// CONSTANT MEMBER FUNCTIONS
sequence::value_type sequence::current( ) const {//     O(1) Time complexity...Same as dynamic array
    assert(is_item());
    return cursor->data();}

bool sequence::is_item( ) const {//     O(1) Time complexity...Same as dynamic array
    return (cursor!=NULL);
}

}
