#include <iostream>
#include <string>

struct Employee
{
	int id{};
	int age{};
	double wage{};
};

int main()
{
	Employee joe;

	joe.age = 32;
	joe.id = 45;
	joe.wage = 40.2;

	std::cout << joe.age << '\n';

	joe = { .id = joe.id, .age = 45, .wage = 20.30 };

	std::cout << joe.age, joe.id, static_cast<int>(joe.wage) << '\n';



	return 0;


}