#include <iostream>

class Foo
{
public:
	explicit Foo()
	{

	}

	explicit Foo(int x)
	{

	}
};

Foo getFoo()
{
	//explicit Foo() cases
	return Foo{ };
	return { };   //error: can't implicitly convert initializer list to Foo


	//explicit Foo(int) cases
	return 5;			// error: can't implicitly convert int to Foo
	return Foo{ 5 };	// ok
	return { 5 };		// error: can't implicitly convert initializer list to Foo
}

int main()
{


	return 0;
}