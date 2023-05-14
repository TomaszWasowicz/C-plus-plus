#include <iostream>

void nullify([[maybe_unusued]] int* ptr2)   //[[maybe_unused]] usuwa warning compilera o ptr2- ustawionym, ale nie u¿ytym
{
	ptr2 = nullptr;   // parametrem funkcji jest null pointer
}

int main()
{
	int x{ 5 };
	int* ptr{ &x };   //ptr wskazuje na x

	std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

	nullify(ptr);

	std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

	return 0;

}