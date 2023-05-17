#include <iostream>

struct Employee
{
	int id{};
	int age{};
	double salary{};
};

int main()
{
	Employee Janek;
	Employee Marek;

	Janek.age = 15;
	Marek.age = 2;

	++Janek.age;

	std::cout << Janek.age << '\n';


	return 0;
}