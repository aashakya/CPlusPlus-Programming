#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MAX_EL 31

class BinNode {
private:
		int data;
		BinNode* left;
		BinNode* right;
	public:
		BinNode() { left = NULL; right = NULL; data = 0; }
		BinNode (int x) { left = NULL; right = NULL; data = x; }
		
		BinNode* getLeft() { return left; }
		BinNode* getRight() {return right; }
		int getData() { return data; }
		
		void setData (int x) { data = x; }
		void setRight (BinNode* newRight) { right = newRight; }
		void setLeft (BinNode* newLeft) { left = newLeft; }
};

class BST2 {
	
	private:
		BinNode* root;
		void printNode(BinNode* myNode);  //to be written in ICE
		bool containsNode(BinNode* myNode,int x); //to be written in ICE
		void insertNode(BinNode* myNode, int x); //to be written in ICE
		void trimLeft(BinNode* myNode); //removes left child of myNode
		void trimRight(BinNode* myNode);  //removes right child of myNode
		void trimRoot();   //removes root node of entire tree
		int getMin(BinNode* myNode);  //helper #1 : find min of subtree myNode
		void removeNode(BinNode* myNode, int x);  //helper #2: remove node with value x from subtree of myNode.
	
		//NEW recursive print functions to help you with debugging
		void printFlattenedNode(BinNode* myNode, int* array, int level);
		void printAsTreeNode(BinNode* myNode, int level);
	
	public:
		BST2();  //to be written in ICE 
		void insert(int x);  //to be written in ICE 
		bool contains(int x);  //to be written in ICE 
		void print();  //to be written in ICE 
		void remove(int x);   //public function to remove x from tree

		//Debugging public function prints
		void printFlattened();
		void printAsTree();
};


void BST2::printNode(BinNode* myNode) {//recursively print in order.  called by public function print()
	if(myNode->getLeft() != NULL){
		printNode(myNode->getLeft());
	}
	cout << myNode->getData() << " ";
	if(myNode->getRight() != NULL){
		printNode(myNode->getRight());
	}
	
}

bool BST2::containsNode(BinNode* myNode, int x) {
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

void BST2::insertNode(BinNode* myNode, int x) {
	
	if (x < myNode->getData()){
		if (myNode->getLeft() != NULL){
			insertNode(myNode->getLeft(), x);
		}
		else{
			BinNode* tmp  = new BinNode();
			tmp->setData(x);//myNode->setLeft(tmp)
			myNode->setLeft(tmp);
		}
		
	}
	else if (x >= myNode->getData()){
		if (myNode->getRight() != NULL){
			insertNode(myNode->getRight(), x);
		}
		else{
			BinNode* tmp  = new BinNode();
			tmp->setData(x);//myNode->setLeft(tmp)
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
		return;
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
		//cout<<"double node"<<endl;
		int minimum = getMin(tmp->getRight());
		//cout<<"double node part 2 "<<minimum<<endl;
		removeNode(myNode, minimum);
		//cout<<"double node part 3"<<endl;
		myNode->getLeft()->setData(minimum);}
		//cout<<"double node part 4"<<endl;
	//CASE 3: left child has two children
	  //find minimum value of left child's right subtree using getMin
	  //remove the node with that value using removeNode
	  //set value of current left child to the minimum value found.
}
	
void BST2::trimRight(BinNode* myNode) {  //trim right child of myNode
	if (myNode->getRight() == NULL){
		return;
	}
	BinNode* tmp = new BinNode; 
	tmp = myNode->getRight();//Make a temporary pointer to the left child.
	
	if (tmp->getRight() == NULL){
		if (tmp->getLeft() == NULL){
			myNode->setRight(NULL);//CASE 1: left child has no children: set current left child pointer to NULL.
		}
		else {myNode->setRight(tmp->getLeft());}//CASE 2A: left child has no left child: set current left to single left grandchild ie the right child
	} 
	else if (tmp->getRight() == NULL && tmp->getLeft() != NULL){
		myNode->setRight(tmp->getLeft());//CASE 2B: left child has no right child: set current left to single left grandchild.
	}
	else{
		int minimum = getMin(tmp->getRight());
		removeNode(myNode, minimum);
		myNode->getRight()->setData(minimum);}
	//same is trimLeft, but on right child.
}
	
void BST2::trimRoot() {  //remove root node from tree.

	if (root == NULL){return;}
	if(root->getLeft() == NULL){
		if (root->getRight()==NULL){
			root = NULL;
		}
		else{root=root->getRight();}
	}
	if (root->getLeft() != NULL && root->getRight() == NULL){
		root = root->getLeft();
	}
	else{
		int minimum = getMin(root->getRight());
		removeNode(root, minimum);
		root->setData(minimum);
	}
	//If root is NULL, return from empty tree.
	//CASE 1: Root has no children, set root to NULL.
	//CASE 2A: Root has no left child, set root to root's getRight
	//CASE 2B: Root has no right child, set root to root's getLeft
	// CASE 3: Root has two children
		//find minimum value in right subtree.
		//Remove the node with that minimum value.
		//Set root's data to that minimum value.
}
	
int BST2::getMin(BinNode* myNode) {
	if (myNode == NULL){
		return INT_MIN;
	}
	BinNode *temp;
	temp = myNode;
	while(temp->getLeft() != NULL){
		temp = temp->getLeft();
	}
	return temp->getData();
	
	//find and return smallest value in subtree with myNode as root.
	//if subtree is myNode is NULL, return INT_MIN
}

BST2::BST2() { root = NULL; }

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

	if (root == NULL) return;
	
	printNode(root);
	
	cout << endl;
	
}

/* int main () {
	//Task 2
	BST2* myBST1 = new BST2();
	BST2* myBST2 = new BST2();
	
	for(int i = 2; i <= 100; i+=2){
		myBST1->insert(i);
	}
	
	for(int i = 100; i >= 2; i-=2){
		myBST2->insert(i);
	}
	
	myBST1->print();
	myBST2->print();
	
	// Task 3
	BST2* myBST3 = new BST2();
	int numbers[343]; // there are 344 numbers that are multiple of 7 from 0 to 2401
	
	for(int i = 0; i <=343; i++){
		numbers[i] = i*7;
	}// adding the numbers in sequence
	
	srand(time(0));
	int temp;
	int index1;
	int index2;
    
	for(int i = 0; i <=1000; i++){//Randomly swapping the numbers location
		index1 = rand()%344;
		index2 = rand()%344;
		temp = numbers[index1];
		numbers[index1] = numbers[index2];
		numbers[index2] = temp;
	}
	cout<<endl;
	for(int i = 0; i <=343; i++){
		cout << numbers[i] << " ";
	}
    

    for(int i = 0; i <=343; i++){
		myBST3->insert(numbers[i]);
	}
    cout << endl;
	cout<<"The Task 3 tree contains: "<<endl;

    myBST3->printAsTree();
    cout<< "Does the sequence contain 700? "<< myBST3->contains(700)<<endl;
    cout<< "Does the sequence contain 1000? "<< myBST3->contains(1000)<<endl;
	myBST3->remove(7);
	cout<<"ok"<<endl;
	myBST3->print();

	return 0;
 }*/
int main () {

	BST2* myBST2 = new BST2();
	
	myBST2->insert(8);                             // insert values into tree
	myBST2->insert(4);
	myBST2->insert(11);
	myBST2->insert(2);
	myBST2->insert(6);
	myBST2->insert(10);
	myBST2->insert(12);
	myBST2->insert(1);
	myBST2->insert(3);
	myBST2->insert(5);
	myBST2->insert(7);
	myBST2->insert(9);
	
	//myBST2->printAsTree();                         // print tree geometrically
	cout <<endl;
	int i;
	cin>>i;
	myBST2->remove(i);
	myBST2->printAsTree();
	return 0;
}

//below are the function definitions for the debugging printing************
void BST2::printAsTree() {
	printAsTreeNode(root, 0);
}


void BST2::printAsTreeNode(BinNode* myNode, int level) {
	
	if (myNode == NULL) return;
	printAsTreeNode(myNode->getRight(), level+1);
	for (int i=0; i<level; i++) // Indent to level
		cout << "   ";
	cout << myNode->getData() << "\n"; // Print node value
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
