#include <iostream>
#include <memory>
#include <utility>

class Resource
{
public:
	Resource()
	{
		std::cout << "Resource stworzony\n";
	}
	~Resource()
	{
		std::cout << "Resource znisczony\n";
	}
};

int main()
{
	std::unique_ptr<Resource> res1{new Resource{}};
	std::unique_ptr<Resource> res2{};     // pocz¹tek jako null_ptr

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	 // res2 = res1;    // nie zkompiluje siê, copy assignment jest wy³¹czony

	res2 = std::move(res1);     //res2 przejmuje w³asnoœæ, res1 jest ustawiana na null

	std::cout << "Ownership transfered\n";

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	return 0;

	//Resource zniszczony kiedy funkcja, w której jest res2, zakañcza scope
}