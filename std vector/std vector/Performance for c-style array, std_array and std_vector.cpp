#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include <cstdlib>

int main()
{
	int						myInt[100000];
	std::array<int, 100000> myArr;
	std::vector<int>		myVec(100000);

	srand(time(NULL));

	// Timing for myInt
	std::chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		myInt[i] = rand() % 100 + 1;
	}
	std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds execTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
	std::cout << "myInt array running time is " << execTime.count() << " ms" << std::endl;

	// Timing for myArr
	timeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		myArr[i] = rand() % 100 + 1;
	}
	timeEnd = std::chrono::high_resolution_clock::now();
	execTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
	std::cout << "myArr array running time is " << execTime.count() << " ms" << std::endl;

	// Timing for myVec
	timeStart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++)
	{
		myVec[i] = rand() % 100 + 1;
	}
	timeEnd = std::chrono::high_resolution_clock::now();
	execTime = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
	std::cout << "myVec array running time is " << execTime.count() << " ms" << std::endl;

	return 0;
}
