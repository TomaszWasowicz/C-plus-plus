#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string myName{ "Alex" };
	myName = "John";

	std::cout << myName << endl; //wyswietlenie zmiennej string, endl - czêœæ biblioteki namespace std

	std::cout << "Hello world!\n";

	return 0;
}