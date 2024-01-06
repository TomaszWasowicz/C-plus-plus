#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex carMutex;

void driveCar(std::string driverName) {

	//automaticall unlocks the code, when it goes out of scope, cannot be unlocked manually
	std::lock_guard<std::mutex>carLock(carMutex);  
	
	//unique_lock<std::mutex> carLock(carMutex);

	std::cout << driverName << " is driving" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << driverName << " is done driving" << std::endl;

	//carLOck.unlock();										//unique_lock case
}

int main()
{
	std::thread t1(driveCar, "Tomek");
	std::thread t2(driveCar, "Kasia");

	t1.join();
	t2.join();


	return 0;
}