#include <iostream>

class Something
{
public:
	static int s_value;   //deklaracja zmiennej statycznej
};

int Something::s_value{ 1 };

int main()
{
	Something::s_value = 2;
	std::cout << Something::s_value << '\n';


	return 0;
}