/**
 * Author: SAHIL SHARMA
 * Date Created: Feb 25, 2018
 * Project: Binary Search Tree in C++
 */


#include "bst.h"
#include <iostream>

using namespace std;

int main() {

	int nums[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

	Bst myTree;
	int input = 0;

	cout << "--------------------" << endl;
	cout << "Adding values in tree." << endl;
	cout << "--------------------" << endl;

	for(int i = 0; i < 16; i++) {
		myTree.addLeaf(nums[i]);
	}
	cout << "Done!" << endl;

	cout << endl;
	cout << "--------------------" << endl;
	cout << "Printing tree Inorder" << endl;
	cout << "--------------------" << endl;

	myTree.printInOrder();
	cout << endl << endl;

	cout << "--------------------" << endl;
	cout << "Printing tree Preorder" << endl;
	cout << "--------------------" << endl;

	myTree.printPreOrder();
	cout << endl << endl;

	cout << "--------------------" << endl;
	cout << "Printing tree Postorder" << endl;
	cout << "--------------------" << endl;

	myTree.printPostOrder();
	cout << endl << endl;

	return 0;
}