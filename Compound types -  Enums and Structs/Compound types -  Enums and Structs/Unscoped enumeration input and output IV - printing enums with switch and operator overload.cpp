#include <iostream>

enum Color
{
	black,
	red,
	blue,
};

// Teach std::cout how to print a Color
// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
	switch (color)
	{
	case black: out << "black";  break;
	case red:   out << "red";    break;
	case blue:  out << "blue";   break;
	default:    out << "???";    break;
	}

	return out;
}

int main()
{
	Color shirt{ blue };
	std::cout << "Your shirt is " << shirt; // it works!

	return 0;
}