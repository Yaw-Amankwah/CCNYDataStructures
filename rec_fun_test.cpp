//  rec_fun_test.cpp
//  STUDENT: YAW AMANKWAH
//  ID: ****3700
//  INTEGRITY STATEMENT:
//  “The work in this assignment is my own. Any outside sources have been properly cited.”

#include <stdio.h>
#include <iostream>
#include "rec_fun.h"

int main(int argc, const char * argv[]) {
   
   //   TESTING INDENTED SENTENCES
    std::cout << "NOW TESTING THE INDENTED SENTENCES FUNCTION: " << std::endl;
    std::cout << "\nINDENTED_SENTENCES (0,0): " << std::endl;
    indented_sentences(0, 0);
    std::cout <<  "\nINDENTED_SENTENCES (0,1): " <<std::endl;
    indented_sentences(0, 1);
    std::cout <<  "\nINDENTED_SENTENCES (1,1): " <<std::endl;
    indented_sentences(1, 1);
    std::cout <<  "\nINDENTED_SENTENCES (1,5): " <<std::endl;
    indented_sentences(1, 5);
    //std::cout <<  "\nINDENTED_SENTENCES (5,1): " <<std::endl;
    //indented_sentences(5, 1);
    std::cout << std::endl;
    
    //  TESTING TRIANGLE
    std::cout << "NOW TESTING THE TRIANGLE FUNCTION: " << std::endl;
    std::cout << "\nTRIANGLE (0,0): " << std::endl;
    triangle(std::cout,0, 0);
    std::cout << "\nTRIANGLE (0,1): " << std::endl;
    triangle(std::cout,0, 1);
    std::cout <<  "\nTRIANGLE (1,1): " <<std::endl;
    triangle(std::cout,1, 1);
    std::cout <<  "\nTRIANGLE (1,5): " <<std::endl;
    triangle(std::cout,1, 5);
    //std::cout << "\nTRIANGLE (5,1): " << std::endl;
    //triangle(std::cout,5, 1);
    std::cout << std::endl;
    
    // TESTING BINARY PRINT
    std::cout << "NOW TESTING THE BINARY PRINT FUNCTION: " << std::endl;
    std::cout << "\nBINARY_PRINT (cout, 0): " << std::endl;
    binary_print(std::cout, 0);
    std::cout << "\nBINARY_PRINT (cout, 1): " << std::endl;
    binary_print(std::cout, 1);
    std::cout << "\nBINARY_PRINT (cout, 2): " << std::endl;
    binary_print(std::cout, 2);
    std::cout << "\nBINARY_PRINT (cout, 7): " << std::endl;
    binary_print(std::cout, 7);
    std::cout << "\nBINARY_PRINT (cout, 10): " << std::endl;
    binary_print(std::cout, 10);
    std::cout << "\nBINARY_PRINT (cout, 27): " << std::endl;
    binary_print(std::cout, 27);
    std::cout << "\nBINARY_PRINT (cout, 100): " << std::endl;
    binary_print(std::cout, 100);
    std::cout << std::endl;
    
    //TESTING POWER
    std::cout << "\nNOW TESTING THE POWER FUNCTION: " << std::endl;
    std::cout << "\nPOWER (0,3): " << power(0, 3) << std::endl;
    std::cout << "\nPOWER (1,0): " << power(1, 0) << std::endl;
    std::cout << "\nPOWER (1,3): " << power(1, 3) << std::endl;
    std::cout << "\nPOWER (3,0): " << power(3, 0) << std::endl;
    std::cout << "\nPOWER (3,3): " << power(3, 3) << std::endl;
    std::cout << "\nPOWER (2.5,0): " << power(2.5, 0) << std::endl;
    std::cout << "\nPOWER (2.5,3): " << power(2.5, 3) << std::endl;
    //std::cout << "\nPOWER (0,0): " << power(0, 0) << std::endl;
    //std::cout << "\nPOWER (0,-2): " << power(0, -2) << std::endl;
    //std::cout << "\nPOWER (1,-2): " << power(1, -2) << std::endl;
    //std::cout << "\nPOWER (3,-2): " << power(3, -2) << std::endl;
    //std::cout << "\nPOWER (2.5,-2): " << power(2.5, -2) << std::endl;



    
  
      
    

    
    return 0;
}
