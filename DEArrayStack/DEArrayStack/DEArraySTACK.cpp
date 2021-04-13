#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXELEMENTS 50                        // list max length = 50

#include "DEArraySTACK.h"

// ********************************************************************************************** //
// DEArraySTACK class member functions                                                            //
// Double-ended stack abstract data type implemented with array data structure                    //
// ********************************************************************************************** //

bool DEArraySTACK::pushFront(int j){        
   if (j < 1){
      cout << "Elements are positive non-zero values.  Cannot push." << endl;
      return false; // returning false with error message when j is negative or 0
   }
   if (elementsFront+elementsBack == MAXELEMENTS){
       cout << "Max elements reached.  Cannot push."<< endl;
       return false; // returning false with error message when at MAXELEMENT
   }
   for (int i = elementsFront; i > 0; i--){
       data[i] = data[i-1]; // shifting value of the elements to the right
   }
   data[0] = j; // storing j into the first element (pushing the values of j)
   elementsFront++; // setting up the new element size
   return true; // returning true if successful
};

int  DEArraySTACK::popFront(){              
    if (elementsFront == 0){
       return -1; // returning -1 when the stack is empty
   }
   int temp = data[0];// storing the value to be popped to temporary
   for (int i = 0; i < elementsFront; i++){
       data[i] = data[i+1]; // shifting value of the elements to the left
   }
   data[elementsFront] = 0; // setting up the vacated location to 0
   elementsFront--; // setting up the new element size
   return temp;
};

// ***************************     THIS IS COMPLETED FOR YOU    ********************************
int  DEArraySTACK::topFront(){              // Return integer from front of DE stack.  Do not
                                            // alter the stack.  If front stack empty, return -1.
        if (elementsFront==0) return -1; 
        return data[0];
};


bool DEArraySTACK::pushBack(int j){         
    if (j < 1){
      cout << "Elements are positive non-zero values.  Cannot push." << endl;
      return false; // returning false with error message when j is negative or 0
   }
   if (elementsFront+elementsBack == MAXELEMENTS){
       cout << "Max elements reached.  Cannot push."<< endl;
       return false; // returning false with error message when at MAXELEMENT
   }
   for (int i = MAXELEMENTS-elementsBack; i < MAXELEMENTS; i++){
       data[i-1] = data[i]; // shifting value of the elements to the left
   }
   data[MAXELEMENTS-1] = j; // storing j into the first element of the back stack(pushing the values of j)
   elementsBack++; // setting up the new element size of the back stack
   return true; // returning true if successful
};
                                            

// ***************************     THIS IS COMPLETED FOR YOU    ********************************
int  DEArraySTACK::popBack(){               // Pop integer from front of DE stack.  If successful
                                            // return value of popped element.  If empty, return -1.
                                            // Vacated locations are set to zero.
        if (elementsBack==0) return -1;     
        int topBack=data[MAXELEMENTS-1];

        for (int i=MAXELEMENTS-1; i>MAXELEMENTS-1-elementsBack; i--) data[i]=data[i-1];   // Shift back data.
        data[MAXELEMENTS-1-elementsBack]=0;  // Set vacated value to 0;
        elementsBack--;

        return topBack;
};


int  DEArraySTACK::topBack(){  
    if (elementsBack == 0){
        return -1; // returning -1 when the stack is empty
    }
    return data[MAXELEMENTS-1];// Return integer from back of DE stack
};

// ***************************     THIS IS COMPLETED FOR YOU    ********************************
void DEArraySTACK::printStack(){
     for (int i=0; i<MAXELEMENTS; i++) cout << data[i] << " ";
     cout << endl;
};


// ***************************     THIS IS COMPLETED FOR YOU    ********************************
void DEArraySTACK::printElementCounts() { cout << "elementsFront= " << elementsFront;
                                  cout << "    elementsBack= " << elementsBack << endl << endl;
};


