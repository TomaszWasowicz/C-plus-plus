#include <iostream>
#include <array>

void passValue(int& value)
{
	value = 99;
}

void passArray(std::array<int,5>& prime)
{
	prime[0] = 11;
	prime[1] = 7;
	prime[2] = 5;
	prime[3] = 3;
	prime[4] = 2;
}

int main()
{
	int value{ 1 };
	std::cout << "before passValue: " << value << '\n';
	passValue(value);
	std::cout << "after passValue: " << value << '\n';

	std::array<int,5> prime{ 2,3,5,7,11 };
	std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " <<
		prime[2] << " " << prime[3] << " " << prime[4] << '\n';
	passArray(prime);
	std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << 
		prime[2] << " " << prime[3] << " " << prime[4] << '\n';


	return 0;
}