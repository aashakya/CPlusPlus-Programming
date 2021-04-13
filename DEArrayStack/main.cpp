#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXELEMENTS 50                        // list max length = 50

#include "DEArraySTACK.h"


void easytest(DEArraySTACK *testStack);
void meditest(DEArraySTACK *testStack);
void hardtest(DEArraySTACK *testStack);


// ************************************************************************************************ //
//                                                                                                  //
// program:    main.cpp                                                                             //
//                                                                                                  //
// programmer: ece 252                           date: 03/17/2021                                   //
//                                                                                                  //
// description:                                                                                     //
//          this main() tests a double-ended stack dADT.  the user is prompted for one of three     //
//          testbenches.  the list is to have a maximum of 50 elements.                             //
//                                                                                                  //
// notes:   this file is not to be edited.                                                          //
//                                                                                                  //
// ************************************************************************************************ //


int main() {

    DEArraySTACK* myStack = new DEArraySTACK();    // instantiate double-ended Stack with array object
    int x=0;                                       // user choice variable

    cin >> x;                                      // accept user choice

    if (x==0) easytest(myStack);                   // easier front end push-pop test
    if (x==1) meditest(myStack);                   // medium double-ended push-pop test
    if (x==2) hardtest(myStack);                   // harder double-ended push-pop overrun test

    return 0;
}



// ************************************************************************************************ //
// function: easytest(DEArraySTACK *testStack)                                                      //
// purpose:  performs low impact testing                                                            //
// ************************************************************************************************ //
void easytest(DEArraySTACK *testStack) {

    cout << "Easy Test " << endl << "-----------" << endl << endl;

    cout << "Starting point: " << endl;                        // Print the empty stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(101) " << endl;                         // Push 101 onto the front stack
    testStack->pushFront(101);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(102) " << endl;                         // Push 102 onto the front stack
    testStack->pushFront(102);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    return;
}


// ************************************************************************************************ //
// function: meditest(DEArraySTACK *testStack)                                                      //
// purpose:  performs medium impact testing                                                         //
// ************************************************************************************************ //
void meditest(DEArraySTACK *testStack) {

    cout << "Medium Test " << endl << "-------------" << endl << endl;

    cout << "Starting point: " << endl;                        // Print the empty stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(101) " << endl;                         // Push 101 onto the front stack
    testStack->pushFront(101);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(102) " << endl;                         // Push 102 onto the front stack
    testStack->pushFront(102);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(103) " << endl;                         // Push 103 onto the front stack
    testStack->pushFront(103);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(901) " << endl;                          // Push 901 onto the back stack
    testStack->pushBack(901);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(902) " << endl;                          // Push 902 onto the back stack
    testStack->pushBack(902);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popBack() = " << testStack->popBack() << endl;    // Pop the back stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(903) " << endl;                          // Push 903 onto the back stack
    testStack->pushBack(903);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    return;
}

// ************************************************************************************************ //
// function: hardtest(DEArraySTACK *testStack)                                                      //
// purpose:  performs high impact testing                                                           //
// ************************************************************************************************ //
void hardtest(DEArraySTACK *testStack) {

    cout << "Hard Test " << endl << "-----------" << endl << endl;

    cout << "Starting point: " << endl;                        // Print the empty stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(101) " << endl;                         // Push 101 onto the front stack
    testStack->pushFront(101);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(101) " << endl;                         // Push 101 onto the front stack
    testStack->pushFront(101);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(102) " << endl;                         // Push 102 onto the front stack
    testStack->pushFront(102);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popFront() = " << testStack->popFront() << endl;  // Pop the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(103) " << endl;                         // Push 103 onto the front stack
    testStack->pushFront(103);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(-2) " << endl;                          // Push -2 onto the front stack
    testStack->pushFront(-2);                                  // Fails due to negative
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(901) " << endl;                          // Push 901 onto the back stack
    testStack->pushBack(901);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(902) " << endl;                          // Push 902 onto the back stack
    testStack->pushBack(902);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "popBack() = " << testStack->popBack() << endl;    // Pop the back stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushBack(903) " << endl;                          // Push 903 onto the back stack
    testStack->pushBack(903);
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "Pushing 46 elements on front to fill. " << endl;  // Push 501-546 onto the front stack
    for (int i=501; i<547; i++) testStack->pushFront(i);       // Push 46 elements onto the front stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    cout << "pushFront(100) fails due to full stack. " << endl;// Push 100 onto the front stack
    testStack->pushFront(100);                                 // Fails due to full stack
    testStack->printStack();                                   // Print the stack
    testStack->printElementCounts();                           // Print the element counts

    return;
}




