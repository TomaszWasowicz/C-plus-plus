#include <iostream>

class Something
{
private:
	static int s_value;
public:
	static int getValue() { return s_value; } //static member function
};

int Something::s_value{ 1 };  // initializer

int main()
{
	std::cout << Something::getValue() << '\n';


	return 0;
}