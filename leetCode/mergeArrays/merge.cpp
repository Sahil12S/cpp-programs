/**
 * Author: SAHIL SHARMA
 * Created On: 03/07/2018
 * Question: Merge 2 sorted arrays into 1 which has enough empty sapce to hold all elements of the other array.
 */

#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main() {
	int m = 9;
	int n = 4;

	vector<int> nums1(m);
	nums1[0] = 1;
	nums1[1] = 5;
	nums1[2] = 8;
	nums1[3] = 10;
	nums1[4] = 12;



	vector<int> nums2 = {2, 9, 11, 14};





	return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int>::iterator it1 = nums1.end();
	vector<int>::iterator it2 = nums2.end();

	cout << *it1 << endl;

	while(it1 != nums1.begin() && it2 != nums2.begin()) {
		


		it1--;
		it2--;
	}
}