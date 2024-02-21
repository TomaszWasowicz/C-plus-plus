#include <array>
#include <iostream>
#include<functional>

int main(){

	int x{ 1 };
	int y{ 2 };
	int z{ 3 };

	//[[maybe_unused]] std::array <int&, 2> refarr{ x,y }; //compile error. cannot define array of references

	int& ref1{ x };
	int& ref2{ y };

	std::array valarr{ ref1, ref2 }; //std::array<int, 2 >, not an array of references

	std::array<std::reference_wrapper<int>, 3>arr{ x,y,z };

	arr[1].get() = 5;

	std::cout << arr[1] << y << '\n';


	return 0;
}

