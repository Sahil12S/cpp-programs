#include <iostream>
#include <vector>

using namespace std;

void doInsertionSort(vector<int>& nums);

int main() {
	vector<int> nums = {4, 12, 5, 1, 6, 10, 8, 3};

	doInsertionSort(nums);

	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}

void doInsertionSort(vector<int>& nums) {
	if(nums.size() <= 1) return;

	for(int i = 0; i < nums.size(); i++) {
		int j = i;
		while(j > 0 && nums[j] < nums[j - 1]) {
			int temp = nums[j];
			nums[j] = nums[j - 1];
			nums[j - 1] = temp;
			j--;
		}
	}

}


/*
a[] = 4, 12, 5, 1, 6, 10, 8, 3

for j = 1; j < array_size; j++
	i = j
	while a[i] < a[i-1] && i >= 1
		temp = a[i]
		a[i] = a[i-1]
		a[i-1] = temp
		i--

j = 1; a[j] = 12
j = 2; a[j] = 5
	i = 2
	temp = 5
	a[2] = a[1] => a[2] = 12
	a[1] = 5		4, 5, 12, 1, 6, 10, 8, 3
	i = 1
j = 3; a[j] = 1
	i = 3
	temp = 1
	a[3] = 12
	a[2] = 1		4, 5, 1, 12, 6, 10, 8, 3
	i = 2
	a[2] < a[1]: 1 < 5
	temp = 1
	a[2] = 5
	a[1] = 1		4, 1, 5, 12, 6, 10, 8, 3
	i = 1
	temp = 1
	a[1] = 4
	a[0] = 1		1, 4, 5, 12, 6, 10, 8, 3
	i = 0
*/