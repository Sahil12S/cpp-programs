//============================================================================
// Name        : SingletonDP.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Singleton Deign Pattern in C++. Only one instance can exist at a given time.
//============================================================================

#include <iostream>

class Leader {
private:
	static Leader* _instance;

//	Constructor is private in Singleton design pattern.
	Leader() {
		std::cout << "New Leader is elected." << std::endl;
	}

public:
	static Leader* getInstance() {
		if(_instance == NULL) {
			_instance = new Leader;
		}
		return _instance;
	}

	void giveSpeech() {
		std::cout << "Address the public." << std::endl;
	}
};

Leader* Leader::_instance = NULL;

int main() {

//	Leader* elected = new Leader();
	Leader::getInstance() -> giveSpeech();

	Leader* elected = elected -> getInstance();
	elected -> giveSpeech();

/*	Leader* elected = Leader::getInstance();
	elected->giveSpeech();*/
//	return 0;
}
