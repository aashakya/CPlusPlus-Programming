#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

#define MAX_EL 31

#include "BST2.h"

BST2::BST2() { root = NULL; }

void BST2::printNode(BinNode* myNode) {            // recursively print in order.  called by public function print()
	if(myNode->getLeft() != NULL){
		printNode(myNode->getLeft());
	}
	cout << myNode->getData() << " ";
	if(myNode->getRight() != NULL){
		printNode(myNode->getRight());
	}
}

bool BST2::containsNode(BinNode* myNode, int x) {  // insert code from ICE here
	if (myNode->getData() < x && myNode->getRight() != NULL){
		return containsNode(myNode->getRight(), x);
	}
	else if (myNode->getData() > x && myNode->getLeft() != NULL){
		cout<<myNode->getData()<<endl;
		return containsNode(myNode->getLeft(), x);
	}
	else if (myNode->getData() == x){
		return true;
	}
	return false;
}

void BST2::insertNode(BinNode* myNode, int x) {    // insert code from ICE here
	if (x < myNode->getData()){
		if (myNode->getLeft() != NULL){
			insertNode(myNode->getLeft(), x);
		}
		else{
			BinNode* tmp  = new BinNode();
			tmp->setData(x);
			myNode->setLeft(tmp);
		}
	}
	else if (x >= myNode->getData()){
		if (myNode->getRight() != NULL){
			insertNode(myNode->getRight(), x);
		}
		else{
			BinNode* tmp  = new BinNode();
			tmp->setData(x);
			myNode->setRight(tmp);
		}
	}
}

void BST2::removeNode(BinNode* myNode, int x) {  //remove node with value x from subtree of myNode.
	if (x < myNode->getData()){ // Checking if the value of x could be in the left side of the tree
		if (myNode->getLeft() == NULL){
			return;//If the left subtree is NULL, the value is not in the tree.  Return.
		}
		else if (myNode->getLeft()->getData() == x){
			trimLeft(myNode); // if data is found on the left side, trimLeft is called
		} 
		else{removeNode(myNode->getLeft(),x);}// recursively removeNode on left child to look deeper.
	}
	
	else {
		if (myNode->getRight() == NULL){
			return;//If the right subtree is NULL, the value is not in the tree.  Return.
		}
		else if (myNode->getRight()->getData() == x){
			trimRight(myNode); // if data is found on the right side, trimRight is called
		}
		else{removeNode(myNode->getRight(),x);}// recursively removeNode on right child to look deeper.
	}
}
	
void BST2::trimLeft(BinNode* myNode) {  //Remove the left child of myNode
	if (myNode->getLeft() == NULL){
		return; // if the node to be removed is NULL, return
	}
	BinNode* tmp = new BinNode; 
	tmp = myNode->getLeft();//Make a temporary pointer to the left child.
	if (tmp->getLeft() == NULL){
		if (tmp->getRight() == NULL){
			myNode->setLeft(NULL);//CASE 1: left child has no children: set current left child pointer to NULL.
		}
		else {myNode->setLeft(tmp->getRight());}//CASE 2A: left child has no left child: set current left to single left grandchild ie the right child
	} 
	else if (tmp->getRight() == NULL && tmp->getLeft() != NULL){
		myNode->setLeft(tmp->getLeft());//CASE 2B: left child has no right child: set current left to single left grandchild.
	}
	else{
		int minimum = getMin(tmp->getRight()); //calling getMin to find the leftmost value of the right node
		removeNode(myNode, minimum);//removing the minimum node
		myNode->getLeft()->setData(minimum);// setting the left of myNode to the minimum value
    }
}
	
void BST2::trimRight(BinNode* myNode) {  //trim right child of myNode
	if (myNode->getRight() == NULL){
		return;// if the note to be removed is NULL, return
	}
	BinNode* tmp = new BinNode; 
	tmp = myNode->getRight();//temporary pointer to the right child.
	
	if (tmp->getRight() == NULL){
		if (tmp->getLeft() == NULL){
			myNode->setRight(NULL);//CASE 1: right child has no children: set current right child pointer to NULL.
		}
		else {myNode->setRight(tmp->getLeft());}//CASE 2A: right child has no left child: set current left to single left grandchild ie the right child
	} 
	else if (tmp->getRight() == NULL && tmp->getLeft() != NULL){
		myNode->setRight(tmp->getLeft());//CASE 2B: right child has no right child: set current left to single left grandchild.
	}
	else{
		int minimum = getMin(tmp->getRight());//calling getMin to find the leftmost value of the right node
		removeNode(myNode, minimum); //removing the minimum node
		myNode->getRight()->setData(minimum); // setting the right of myNode to the minimum value
    }
}
	
void BST2::trimRoot() {  //remove root node from tree.
	if (root == NULL){return;} //If root is NULL, return from empty tree.
	if(root->getLeft() == NULL){
		if (root->getRight()==NULL){
			root = NULL; //CASE 1: Root has no children, set root to NULL.
		}
		else{root=root->getRight();}//CASE 2A: Root has no left child, set root to root's getRight
	}
	if (root->getLeft() != NULL && root->getRight() == NULL){
		root = root->getLeft(); //CASE 2B: Root has no right child, set root to root's getLeft
	}
	else{ // Case 3 with 2 children
		int minimum = getMin(root->getRight());//calling getMin to find the leftmost value of the right node
		removeNode(root, minimum); //removing the minimum node
		root->setData(minimum); // setting the right of myNode to the minimum value
	}
}

int BST2::getMin(BinNode* myNode){
	if (myNode == NULL){
		return INT_MIN;//if subtree is myNode is NULL, return INT_MIN
    }
	BinNode *temp;
	temp = myNode; // setting the mynode into temporary
	while(temp->getLeft() != NULL){
		temp = temp->getLeft(); // finding the minimum value in the tree
	}
	return temp->getData();// returning the minimum value
}

void BST2::insert (int x) {
	if (root == NULL) {
		BinNode* tmp = new BinNode(x);
		root = tmp;
	}
	else insertNode(root, x);
}

void BST2::remove (int x) {
    if (root == NULL){return;}//If root is NULL, return from empty tree.
	else if (root->getData() == x){trimRoot();}//if root's data matches number to be removed, trimRoot.
	else {removeNode(root,x);}//else, call recursive function removeNode on root.
}

bool BST2::contains (int x) {
    if (root == NULL) return false;
	return containsNode(root, x);
}

void BST2::print () {
	printNode(root);
	cout << endl;
}

// ****************************************************************************
// the functions below provided to aid you in debugging by allowing two added
// views of the tree.  you may use them to help you see your tree as you 
// perform various operations.  they are for debugging purposes only

void BST2::printAsTree() {
	printAsTreeNode(root, 0);
}


void BST2::printAsTreeNode(BinNode* myNode, int level) {
	
	if (myNode == NULL) return;
	printAsTreeNode(myNode->getRight(), level+1);
	for (int i=0; i<level; i++) cout << "   ";     // indent to level
	cout << myNode->getData() << "\n";             // print node value
	printAsTreeNode(myNode->getLeft(), level+1);
}


void BST2::printFlattened() {
	
	int data[MAX_EL];
	
	for (int i=0; i < MAX_EL; i++) {
		data[i] = INT_MIN;
	}
	
	if (root==NULL) return;
	
	printFlattenedNode(root, data, 0);
	
	
	cout << endl << "Flattened Tree: [";
	//print array
	for (int i=0; i < MAX_EL; i++) {
		if (data[i] != INT_MIN) cout << data[i];
		else cout << "-";
		cout << " ";
	}
	cout << "]" << endl;
	
}


void BST2::printFlattenedNode(BinNode* myNode, int* array, int level) {
	
	if (level >= MAX_EL) return;
	
	array[level] = myNode->getData();
	
	if (myNode->getLeft() != NULL) printFlattenedNode(myNode->getLeft(), array, 2*level+1);
	if (myNode->getRight() != NULL) printFlattenedNode(myNode->getRight(), array, 2*level+2);

}
// ****************************************************************************
