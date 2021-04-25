// ********************************************************************************************** //
// BinNode and BST2 class                                                                         //
// ********************************************************************************************** //
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
		void printNode(BinNode* myNode);           // already written in ICE
		bool containsNode(BinNode* myNode,int x);  // already written in ICE
		void insertNode(BinNode* myNode, int x);   // already written in ICE
		void trimLeft(BinNode* myNode);            // removes left child of myNode
		void trimRight(BinNode* myNode);           // removes right child of myNode
		void trimRoot();                           // removes root node of entire tree
		int getMin(BinNode* myNode);               // helper #1 : find min of subtree myNode
		void removeNode(BinNode* myNode, int x);   // helper #2:  remove node with value x 
		                                           //             from subtree of myNode.
		
		                                           // NEW print functions provided to help 
												   // you with debugging - geometric and flat
		void printFlattenedNode(BinNode* myNode, int* array, int level);
		void printAsTreeNode(BinNode* myNode, int level);		
	
	public:
		BST2();                                    // already written in ICE
		void insert(int x);                        // already written in ICE
		bool contains(int x);                      // already written in ICE
		void print();                              // already written in ICE
		void remove(int x);                        // public function to remove x from tree
		
		void printFlattened();                     // shell for full tree printing (flattened)
		void printAsTree();                        // shell for full tree printing (geometric)
		
};

