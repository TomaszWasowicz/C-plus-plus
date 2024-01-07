#include<iostream>

int main()
{
	int x{ 5 };

	int const* ptr = nullptr;
	int const* ptr2{};
	int const* ptr3{ &x };

	std::cout << *ptr3 << '\n';  //dereferencja


	return 0;
}