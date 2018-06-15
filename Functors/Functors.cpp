//============================================================================
// Name        : Functors.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Functors: Function objects
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class A {
public:
	void operator()(std::string str) {
		std::cout << "function A : " << str << std::endl;
	}
};

class B {
public:
	B(int i)
		: id(i) {}

	void operator()(std::string str) {
		std::cout << "function B : " << str << std::endl;
	}

private:
	int id;
};

class C {
public:
	C(int i) : val(i) {}

	void operator()(int num) {
		std::cout << "result: " << num + val << std::endl;
	}

private:
	int val;

};

int main() {

	A a_obj;
	a_obj("Hello!!");	// Using an object as if it was a function.

	B(12)("Hello again!!");

	std::vector<int> myVector = {1, 2, 3, 4, 5};

	int val = 10;

	for_each( myVector.begin(), myVector.end(), C(val) );

	return 0;
}

/**
 * * *		FUNCTORS		* * *
 * Claim :
 * We're not simple plain functions. We're smart. We feature more than operator(). We can have states.
 * For example, the class A can have its member for the state. Also, we can have types as well.
 * We can differentiate function by their signature. We have more than just the signature.
 *
 */
