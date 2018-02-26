/**
 * Author: SAHIL SHARMA
 * Date Created: Feb 25, 2018
 * Project: Binary Search Tree in C++
 */


#ifndef BSt_H
#define BST_H

class Bst {
private:

	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	// Root node of the tree.
	Node* root;

	// Create a leaf node for the tree.
	Node* createLeaf(int data);

	// Add leaf to the tree.
	Node* addLeafPrivate(int data, Node* ptr);

public:
	Bst();

	~Bst();

	void addLeaf(int data);
};




#endif