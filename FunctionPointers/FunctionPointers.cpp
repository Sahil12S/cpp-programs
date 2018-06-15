//============================================================================
// Name        : FunctionPointers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

/*void HelloWorld(int a) {
	std::cout << "Hello World!! Num: " << a << std::endl;
}*/

/*void PrintValue(int value) {
	std::cout << "Value: " << value << std::endl;
}*/

//		Test 3
void ForEach(std::vector<int> myVector, void(*func)(int)) {
	for (int value : myVector)
		func(value);
}


// TEST 4
//void my_func(int x) {
//	std::cout << x << std::endl;
//}


int main() {


//	Style 1
//	auto function = HelloWorld;
// Style 2.
//	void(*otherFunc)(int) = HelloWorld;
//	Style 3.
//	typedef void(*HelloWorldFunc)(int);

//	HelloWorldFunc function2 = HelloWorld;

//	function(2);
//	otherFunc(5);
//	function2(8);


// 	Test 3
	std::vector<int> myVector = {1, 2, 4, 5, 6, 8, 9};

//	ForEach(myVector, PrintValue);

//	Using lambda functions instead of sep arate function
	ForEach(myVector, [](int value) { std::cout << "Value: " << value << std::endl; });


//	TEST 4
//	void (*foo)(int);
//	foo = my_func;
//	my_func(2);
//	(*foo)(10);

	return 0;
}

/**
 ****	 Function pointers	****
 * void (*foo)(int);
 * *foo is function that takes an argument int and return void.
 *
 */
