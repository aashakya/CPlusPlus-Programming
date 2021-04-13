// ********************************************************************************************** //
// DEArraySTACK class                                                                             //
// Double-ended stack abstract data type implemented with array data structure                    //
// ********************************************************************************************** //

class DEArraySTACK {

    private:
        int data[MAXELEMENTS];              // Array data block of max MAXELEMENT positive integers
        int elementsFront;                   // Element count for front stack
        int elementsBack;                    // Element count for back stack

    public:
        DEArraySTACK() { for (int i=0; i<MAXELEMENTS; i++) data[i]=0; elementsFront=0; elementsBack=0; }
                                            // Empty locations are to be set to zero

        bool pushFront(int j);              // Push integer onto front of DE stack.  If successful,
                                            // return true.  If at MAXELEMENTS, return false and  
                                            // specified error message.  If j is 0 or negative, return 
                                            // false and specified error message.

        int  popFront();                    // Pop integer from front of DE stack.  If successful,
                                            // return value of popped element.  If empty, return -1.

        int  topFront();                    // Return integer from front of DE stack.  Do not
                                            // alter the stack.  If empty, return -1.

        bool pushBack(int j);               // Push integer onto rear of DE stack.  If successful,
                                            // return true.  If at MAXELEMENTS, return false and  
                                            // specified error message.  If j is 0 or negative, return 
                                            // false and specified error message.

        int  popBack();                     // Pop integer from front of DE stack.  If successful,
                                            // return value of popped element.  If empty, return -1.

        int  topBack();                     // Return integer from back of DE stack.  Do not
                                            // alter the stack.  If empty, return -1.

        void printStack();

        void printElementCounts();

};

