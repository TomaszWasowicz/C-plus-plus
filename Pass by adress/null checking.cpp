#include <iostream>
#include <cassert>

void print(const int* ptr) // now a pointer to a const int
{
	assert(ptr); // fail the program in debug mode 
			//if a null pointer is passed (since this should never happen)

	// (optionally) handle this as an error case in production mode 
	//so we don't crash if it does happen
	if (!ptr)
		return;

	std::cout << *ptr;
}

int main()
{
	int x{ 5 };

	print(&x);
	print(nullptr);

	return 0;
}