#include <iostream>
#include <vector>

int main()
{
	std::vector v{ 1,2,3,4,5,6,7 };

	auto it{ v.begin() };

	++it;  //move to a second element
	std::cout << *it << '\n';   //print 2

	v.erase(it);   //erase the element currently being iterated over


	// FIX
	// the way to fix the error - erase the element currently being iterated over,
	//set 'it' to the next element
	//it = v.erase(it);  


	//erase() invalidates iterators to the erased element(and subsequent elements)
	//so iterator "it" is now invalidated

	++it;  //undefined behaviour if not fixed like above
	std::cout << *it << '\n';	//undefined behaviour if not fixed like above


	return 0;
}