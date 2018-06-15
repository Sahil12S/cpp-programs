//============================================================================
// Name        : VirtualDestructors.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Virtual Destructors
//============================================================================

#include <iostream>

class BaseClass {
public:
	BaseClass() {
		std::cout << "Base Constructor called." << std::endl;
	}

	virtual ~BaseClass() {
		std::cout << "Base Destructor called." << std::endl;
	}
};

class DerivedClass : public BaseClass {
public:
	DerivedClass() {
		std::cout << "Derived Constructor called." << std::endl;
	}

	~DerivedClass() {
		std::cout << "Derived Destructor called." << std::endl;
	}
};


int main() {

	BaseClass *b = new DerivedClass();

	delete b;

	return 0;
}


/**
 * Difference between virtual destructor and non-virtual destructors:
 *
 * when destructor was not virtual, derived class's destructor was not called, resulting in resource leak.
 * when it was made virtualized both class's destructors were called.
 */
