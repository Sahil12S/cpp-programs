/**
 * Count number of primes less than a non-negative number n.
 * LeetCode question.
 * 
 * Done on Feb 28, 2018
 * Author: SAHIL SHARMA
 */

#include <iostream>

using namespace std;


int countPrimes(int n);

int main() {

	int num = 20;

	cout << "Number of primes: " << countPrimes(num) << endl;

	return 0;
}

int countPrimes(int n) {
	
	if(n < 2)  return 0;

	vector<bool> nums(n, true);
	int count = 0;

	for(int i = 2; i < n; i++) {
		if(nums[i]){
			count++;
		}

		if(i > sqrt(n)) continue;

		for(int j = i; j < n; j += i) {
			if(nums[j]) {
				nums[j] = false;
			}
		}
	}
	return count;

}