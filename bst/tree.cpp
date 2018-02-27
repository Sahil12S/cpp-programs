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


	cout << "Adding values in tree..." << endl;
	for(int i = 0; i < 16; i++) {
		myTree.addLeaf(nums[i]);
	}
	cout << "Done!" << endl;

	return 0;
}