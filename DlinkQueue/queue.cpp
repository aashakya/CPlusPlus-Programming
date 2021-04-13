#include <iostream>
using namespace std;

//tests
void test1();
void test2();
void test3();

class DLink {
	private:
		int data;
		DLink* next;
		DLink* prev;
	public:
		DLink() {next = NULL; data = 0; prev = NULL;}
		DLink (int x) {next = NULL; data = x; prev = NULL;}
		
		DLink* getPrev() {return prev;}
		int getData() {return data;}
		DLink* getNext() {return next;}
		
		void setData (int x) {data = x;}
		void setNext (DLink* nextLink) {next = nextLink;}
		void setPrev (DLink* prevLink) {prev=prevLink;}
};

class DLQueue {
	private:
		DLink *front;
		DLink *rear; 
		int size;
		
	public:
		DLQueue(){
            front = new DLink; // Initialzing the front and the rear DLinks
            rear = new DLink; 
            front->setNext(rear); // setting the head/front next to point to the tail
            rear->setPrev(front); // setting the tail/rear previous to point to the head 
            size = 0;
        } //default constructor--create empty queue.
		
		
		bool enqueue(int j){
            DLink *temp = new DLink;
            
            temp->setData(j); // setting the data into a temp DLink
            rear->getPrev()->setNext(temp);// adding the data next to the data of previous of the rear
            temp->setPrev(rear->getPrev());// setting previous of the temp to the data before it
            temp->setNext(rear); // setting the next data of temp to rear
            rear->setPrev(temp); // setting the previous data of rear to temp

            size++;
            return true;
        }  //add an item to the queue.
		
		int dequeue(){  //remove and return the value of the first element.
			if (isEmpty()){return -1;}		 //Return -1 if empty
			DLink *temporarylink = new DLink; // Creating a temporary link that is the 
            temporarylink->setData(front->getNext()->getData());//copying the second data into temporary link
            temporarylink->setNext(front->getNext()->getNext());// copying the next of the second data into the temporary link
            front->setNext(temporarylink->getNext());// setting the next of the front to the second data
            temporarylink->getNext()->setPrev(front);//setting the previous of the new first data to front
            size--;		 //reducing the size by 1
            return temporarylink->getData();// returning the value of data
        }
		int getSize(){
            return size;
        }  //return number of elements in queue.  

		
		int getFirst(){
            if (isEmpty()){return -1;}
            return front->getNext()->getData();
        }  //return value of element at the head of
					  //queue, but do not remove it.  Return -1 if empty

		
		bool isEmpty(){
            if (size == 0){
                return true;// the Queue is empty if the size is equal to 0
            }
            return false;
        };  //return true if queue is empty.

};


int main(void)
{
		int testNum;
		cin >> testNum;
		
		if (testNum == 1) test1();
		if (testNum == 2) test2();
		if (testNum == 3) test3();
	
}	

void test1() {
	DLQueue *myDLQ = new DLQueue();
	
	myDLQ -> enqueue(1);
	myDLQ -> enqueue(2);
	myDLQ -> enqueue(3);
	
	cout << "Size of Q is: " << myDLQ->getSize() << endl;
	
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;

}

void test2() {
	DLQueue *myDLQ = new DLQueue();
	
	cout << "Testing dequeue on empty Q: " << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	
	myDLQ -> enqueue(1);
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	myDLQ -> enqueue(2);
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	myDLQ -> enqueue(3);
	cout << "DQ: " << myDLQ -> dequeue() << endl;
}

void test3() {
	DLQueue *myDLQ = new DLQueue();
	
	if (myDLQ -> isEmpty()) cout << "Queue is empty." << endl;
	else cout << "Queue is not empty." << endl;
	
	myDLQ -> enqueue(5);
	myDLQ -> enqueue(7);
	myDLQ -> enqueue(9);
	myDLQ -> enqueue(11);
	
	cout <<"There are " << myDLQ -> getSize(); 
	cout << " elements in the queue." << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	
	myDLQ -> enqueue(15);
	myDLQ -> enqueue(5);
	myDLQ -> enqueue(35);
	
	cout << "The newest value in the queue is ";
	cout << myDLQ -> getFirst() << "." << endl;

	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;

	cout <<"There are " << myDLQ -> getSize(); 
	cout << " elements in the queue." << endl;
	
	cout << "Enqueueing 10,000 elements..." << endl;
	for (int i=0; i<10000; i++){ myDLQ->enqueue(i);}

	cout <<"There are " << myDLQ -> getSize(); 
	cout << " elements in the queue." << endl;
	
	cout << "Dequeueing 10,000 elements..." << endl;
	for (int i=0; i<10000; i++){myDLQ->dequeue();}

	cout <<"There are " << myDLQ -> getSize(); 
	cout << " elements in the queue." << endl;
		
	myDLQ -> enqueue(15);
	myDLQ -> enqueue(5);
	myDLQ -> enqueue(35);

	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;

	cout <<"There are " << myDLQ -> getSize(); 
	cout << " elements in the queue." << endl;

	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;
	cout << "DQ: " << myDLQ -> dequeue() << endl;

}
