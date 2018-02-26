/**
 * Author: SAHIL SHARMA
 * Date Created: Feb 25, 2018
 * Project: Binary Search Tree in C++
 */

#include "bst.h"
#include <iostream>

using namespace std;


Bst::Bst() {
	root = nullptr;
}

Bst::~Bst() {

}

Bst::Node* Bst::createLeaf(int data) {
	Node* newNode = new Node();

	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

void Bst::addLeafPrivate(int data, Node* ptr) {
	if(root == nullptr) {
		root = createLeaf(data);
	}
	else {
		if(data < ptr->data) {
			if(ptr->left != nullptr) {
				addLeafPrivate(data, ptr->left);
			}
			else {
				ptr->left = createLeaf(data);
			}
		}
		else if(data > ptr->data) {
			if(ptr->right != nullptr) {
				addLeafPrivate(data, ptr->right);
			}
			else {
				ptr->right = createLeaf(data);
			}
		}
		else {
			cout << "Value already exist." << endl;
		}
	}
}


void Bst::addLeaf(int data) {
	addLeafPrivate(data, root);
}
