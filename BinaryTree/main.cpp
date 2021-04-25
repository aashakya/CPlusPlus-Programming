#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

#define MAX_EL 31

#include "BST2.h"

// ************************************************************************************************ //
//                                                                                                  //
// program:    main.cpp                                                                             //
//                                                                                                  //
// programmer: ece 252                           date: 04/10/2021                                   //
//                                                                                                  //
// description:                                                                                     //
//          this main() tests a BST implementation.                                                 //
//                                                                                                  //
// notes:                                                                                           //
//          this file is not to be edited.                                                          //
//                                                                                                  //
// ************************************************************************************************ //


int main () {

	BST2* myBST2 = new BST2();
	
	myBST2->insert(4);                             // insert values into tree
	myBST2->insert(6);
	myBST2->insert(2);
	myBST2->insert(9);
	myBST2->insert(1);
	myBST2->insert(19);
	myBST2->insert(3);
	
	myBST2->printAsTree();                         // print tree geometrically

	myBST2->printFlattened();                      // print tree flattened - note the 
	                                               // correspondence
	

	myBST2->print();                               // remove values
	myBST2->remove(3);
	myBST2->print();
	myBST2->remove(19);
	myBST2->print();
	myBST2->remove(6);
	myBST2->print();
	
    int tmp;
    for (int i=0; i<20; i++ ) {
        tmp = i*i*1427 % 200;
        myBST2->insert(tmp);                      // insert
    }  
	myBST2->print();

	myBST2->remove(32);                            // remove values
	myBST2->printAsTree();
	myBST2->remove(1);
	myBST2->print();
	myBST2->remove(2);
	myBST2->print();
	myBST2->remove(150);
	myBST2->print();
	myBST2->remove(65);
	myBST2->print();
                                                   // remove numbers not in the tree
	myBST2->remove(8);
	myBST2->remove(190);
	myBST2->remove(100);
	
                                                   // insert more numbers
    for (int i=0; i<10; i++ ) {
        tmp = i*i*1361 % 200;
        myBST2->insert(tmp);                       // insert
    }  
	myBST2->print();
	
for (int i=0; i<20; i++ ) {
      tmp = i*i*1427 % 200;
		myBST2->remove(rand()%200);                  // remove values
	}
	myBST2->print();
	
	myBST2->remove(9);
	myBST2->print();
	myBST2->remove(4);
	myBST2->print();
	cout << "end" <<endl;
	
	return 0;
}


