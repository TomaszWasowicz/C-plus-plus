#include <iostream>
#include <memory>

class Resource
{
public:

	Resource()
	{
		std::cout << "Resource acquired\n";
	}
	~Resource()
	{
		std::cout << "Resource destroyed\n";
	}
};

int main()
{
	// allocate a Resource objectr and have it owned by std::unique_ptr
	std::unique_ptr<Resource> res{ new Resource() };

	return 0;
} //res goes out of scope here and the allocated Resource is destroyed