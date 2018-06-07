//============================================================================
// Name        : Multithreading.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Multi-threading in C++
//============================================================================

#include <iostream>
#include <thread>

static bool is_Finished = false;


void DoWork() {

	using namespace std::literals::chrono_literals;

	while (!is_Finished) {
		std::cout << "Working...\n";

//		this_thread: to give command to current thread.
		std::this_thread::sleep_for(1s);
	}
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
}

int main() {

	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
	std::thread worker(DoWork);

	std::cin.get();
	is_Finished = true;

//	Wait for thread to return.
	worker.join();

	std::cout << "Finished" << std::endl;
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;


	std::cin.get();
}
