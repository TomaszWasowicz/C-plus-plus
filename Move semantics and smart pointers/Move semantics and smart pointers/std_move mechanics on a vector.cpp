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

	// wo³a wersjê lvalue push_back'a, która kopiuje str w element tablicy
	v.push_back(str);		

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nPrzenosze str\n";

	//wo³a wersjê rvalue push_back'a, która move'uje str w element tablicy
	v.push_back(std::move(str));

	std::cout << "str: " << str << '\n'; // niezdeterminowany stan
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';


	return 0;
}