#include <iostream>

int foo()
{
	return 5;
}

int goo()
{
	return 6;
}

int main()
{
	int (*fcnPtr)() { &foo };		//fcnPtr points to function foo
	fcnPtr = &goo;					//fcnPtr now points to function goo
	
	return 0;
}