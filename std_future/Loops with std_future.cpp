#include <iostream>
#include <future>
#include <exception>

int thread_Function(int thread_id) {
	int thread_Loop = 0;
	for (int j = 0; j <= 10000; j++) {
		thread_Loop++;
		if ((j % 5000) == 0) {
			std::cout << "Thread Number: " << thread_id << " at the loop number: " << j << '\n';
		}
	}

	return thread_Loop;
}

int main()
{
	int ret = 0;
	std::future<int> my_async_thread[5];
	for (int i = 0; i < 5; i++) {
		my_async_thread[i] = std::async(thread_Function, i);
	}
	for (int i = 0; i < 5; i++) {
		ret = my_async_thread[i].get();
	}
	return ret;
}