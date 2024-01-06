#include <iostream>
#include <thread>
#include <mutex>
#include<array>

int counter = 0;
std::mutex counterMutex;

void incrementCounter()
{
	for (int i = 0; i < 100; ++i)
	{
		std::lock_guard<std::mutex> lock(counterMutex);
		counter++;
	}
}

int main()
{
	const int numThreads = 100;

	std::array<std::thread, numThreads> threads;

	for (auto &thread : threads)
	{
		thread = std::thread(incrementCounter);
	}

	for ( auto &thread : threads)
	{
		thread.join();
	}

	std::cout << "Final counter value: " << counter << std::endl;

	return 0;
}