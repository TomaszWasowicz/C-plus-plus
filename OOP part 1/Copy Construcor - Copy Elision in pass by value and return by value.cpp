#include <iostream>
class Something
{
public:
	Something() = default;
	Something(const Something&)
	{
		std::cout << "Copy constructor called\n";
	}
};

Something rvo()
{
	return Something{};  //calls Something() and copy constructor
}

Something nrvo()
{
	Something s{};		//calls Something()
	return s;			//calls copy constructor
}

int main()
{
	std::cout << "Initializing s1\n";
	Something s1{ rvo() };				//calls copy constructor

	std::cout << "Initializing s2\n";
	Something s2{ nrvo() };				//calls copy constructor

	//Without optimization, the above program would call the copy constructor 4 times:

	//Once when rvo returns Something to main.
	//Once when the return value of rvo() is used to initialize s1.
	//Once when nrvo returns s to main.
	//Once when the return value of nrvo() is used to initialize s2.
	//However, due to copy elision, it’s likely that your compiler 
	// will elide most or all of these copy constructor calls.
	// Visual Studio 2022 elides 3 cases(it doesn’t elide the case where nrvo() returns by value), 
	// and GCC elides all 4.

	return 0;
}