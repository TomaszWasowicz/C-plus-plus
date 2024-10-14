#include <iostream>
#include <thread>
#include <exception>

int thread_Function(int thread_id) {
	int thread_Loop = 0;
	for (int j = 0; j <= 10000; j++) {
		thread_Loop++;
		if ((j % 5000) == 0) {
			std::cout << "Thread Number : " << thread_id << " at the loop number : " << j << std::endl;
		}
	}

	return thread_Loop;
}

int main() 
{
	int ret = 0;
	std::thread my_thread[5];
	for (int i = 0; i < 5; i++) {
		my_thread[i] = std::thread(thread_Function, i);
	}
	for (int i = 0; i < 5; i++) {
		my_thread[i].join();
	}
	return ret;
}