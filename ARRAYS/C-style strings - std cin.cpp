#include <iostream>
#include <iterator>

int main()
{
	char name[255]{};  //inicjalizacja tablicy znaków - c-style stringu

	std::cout << "Enter your name: ";
	std::cin.getline(name, std::size(name));   //rezerwujemy na wejscie 254 znaki + null terminator

	std::cout << "You've entered: " << name << '\n';


	return 0;
}