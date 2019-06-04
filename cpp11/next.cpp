/**
 * Use of std::next that were introduced in C++11
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
	// Let's say we have a vector of ints
	std::vector<int> v {3, 2, 3, 4, 5, 6};

	// Check if it's sorted
	std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';

	// And we know that we have to skip first value
	// So, we can do this in any of 2 ways
	auto begin = std::begin(v);
	begin++;
	std::cout << std::is_sorted(begin, std::end(v)) << '\n';

	// Or we can do something like this
	std::cout << std::is_sorted(std::begin(v) + 1, std::end(v)) << '\n';

	// But what if we have a list
	std::list<int> l {3, 2, 3, 4, 5, 6};
	
	/**
	 * Following line of code will throw error since, iterator for list is not a random access iterator
	 *
	 std::cout << std::is_sorted(std::begin(l) + 1 , std::end(l)) << '\n';

	 */
	// So to move to next position of iterator, we use std::next
	std::cout << "For list" << '\n';
	std::cout << std::is_sorted(std::next(std::begin(l)) , std::end(l)) << '\n';
	
		
	
	return 0;
}
