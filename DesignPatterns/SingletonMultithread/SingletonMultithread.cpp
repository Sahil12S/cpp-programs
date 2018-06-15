//============================================================================
// Name        : SingletonDP.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   :
// Description : Checking multi-threading with Singleton Design Pattern.
//============================================================================

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex leader_mutex;

class Leader {
private:
	static Leader* _instance;
//	Constructor is private in Singleton design pattern.
	Leader() {
		std::cout << "New Leader is elected." << std::endl;
	}

public:
	static Leader* getInstance() {

//		enabling the lock for code segment to prevent any other thread from accessing it.
		leader_mutex.lock();
		if(_instance == NULL) {
			_instance = new Leader;
		}
		leader_mutex.unlock();
		return _instance;
	}

	void giveSpeech(std::string message) {
		std::cout << "Address to public: " << message << std::endl;

	}
};

// Global single instance is created.
Leader* Leader::_instance = NULL;

void findLeader(std::string msg) {
	Leader::getInstance() -> giveSpeech(msg);
}

int main() {

//	Leader* elected = new Leader();
	std::cout << "Starting thread 1..." << std::endl;
	std::thread leader1(findLeader, "Thread 1");

	std::cout << "Starting thread 2..." << std::endl;
	std::thread leader2(findLeader, "Thread 2");

	leader1.join();
	leader2.join();

//	Leader::getInstance() -> getCount();
}
