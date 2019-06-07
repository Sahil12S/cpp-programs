#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <condition_variable>


std::atomic<bool> bDoSomethingNow(false);
std::condition_variable cvDoSomethingNow;
std::mutex mtx;


void SlaveThread()
{
	std::unique_lock<std::mutex> lck(mtx);
	while(1)
	{
		/*
		if(bDoSomethingNow)
		{
			std::cout << "Slave is working..." << '\n';
			bDoSomethingNow = false;
		}
		*/
		cvDoSomethingNow.wait(lck);
		std::cout << "Slave is working..." << '\n';
	}
}


int main()
{
	
	std::thread slave = std::thread(&SlaveThread);

	// Master thread
	int nCount = 0;
	while(1)
	{
		if(nCount % 5 == 0)
		{
			// Do something slave
			// bDoSomethingNow = true;
			cvDoSomethingNow.notify_one();
		}

		std::cout << "Master thread gathering information..." << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		nCount++;
	}	
	return 0;
}
