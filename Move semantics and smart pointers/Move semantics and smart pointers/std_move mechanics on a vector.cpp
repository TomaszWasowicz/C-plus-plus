#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
	std::vector<std::string> v;

	//std::string is movable, std::string_view is not

	std::string str{ "Puk" };

	std::cout << "Kopiuje str\n";

	// wo�a wersj� lvalue push_back'a, kt�ra kopiuje str w element tablicy
	v.push_back(str);		

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nPrzenosze str\n";

	//wo�a wersj� rvalue push_back'a, kt�ra move'uje str w element tablicy
	v.push_back(std::move(str));

	std::cout << "str: " << str << '\n'; // niezdeterminowany stan
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';


	return 0;
}