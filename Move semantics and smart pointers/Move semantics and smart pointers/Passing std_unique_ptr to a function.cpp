#include <iostream>
#include <memory>
#include <utility>

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

// This function takes the ownership of the Resource, which is unwanted
void takeOwnership(std::unique_ptr<Resource> res)
{
	if (res)
		std::cout << *res << '\n';
}

void useResource(const Resource* res)
{
	if (res)
		std::cout << *res << '\n';
	else
		std::cout << "No resource\n";
}

int main()
{
	auto ptr{ std::make_unique <Resource>() };

	//takeOwnership(ptr);  //it won't work
	
	takeOwnership(std::move(ptr));    // move semantics will work

	useResource(ptr.get());          //get() used here to get a pointer to the Resource

	std::cout << "Ending program\n";

	return 0;
}