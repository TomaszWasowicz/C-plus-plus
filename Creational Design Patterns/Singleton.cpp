#include <iostream>

class Singleton {
public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton() {
		std::cout << "Singleton created." << std::endl;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
	Singleton& singleton = Singleton::getInstance();
	return 0;

}