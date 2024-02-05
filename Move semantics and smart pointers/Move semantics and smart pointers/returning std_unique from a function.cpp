#include <memory>
#include <iostream>

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource& res)
	{
		out << "I am a resource";
		return out;
	}
};

std::unique_ptr<Resource>createResource() 
{
	// in c++ 14 move semantics, the move semantics will be employed to transfer
	// the Resource from the return value to the object assigned to ( here: ptr )

	return std::make_unique<Resource>(); // in c++ 17 return is elided
}

int main()
{
	auto ptr{ createResource() };

	//do whatever

	return 0;
}