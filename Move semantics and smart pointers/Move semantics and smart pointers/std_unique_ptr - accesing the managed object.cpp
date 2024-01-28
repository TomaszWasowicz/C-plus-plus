#include <iostream>
#include <memory>

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

int main()
{
	std::unique_ptr<Resource> res{ new Resource{} };

	if (res)	// implicit cast to bool to ensure res contains a Resource
		std::cout << *res << '\n';

	return 0;
}