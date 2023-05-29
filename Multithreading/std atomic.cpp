#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter = 0;

void incrementCounter()
{
	for (int i = 0; i < 100; ++i)
	{
		counter++;
	}
}

int main()
{
	const int numThreads = 100;

	std::thread threads[numThreads];

	for (int i = 0; i < numThreads; i++)
	{
		threads[i] = std::thread(incrementCounter);
	}

	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}

	std::cout << "Final counter value: " << counter << std::endl;

	return 0;
}