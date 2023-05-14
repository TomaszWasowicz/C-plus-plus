#include <iostream>

class Something
{
public:
	Something(int n = 0, double d = 1.2){}   
	//default constructor, mozna stworzyc Something(int,double), Something(int) or Something()
};

int main()
{
	Something s1{ 1,2.4 };
	Something s2{ 1 };
	Something s3{};

	Something s4{ 2.4 };				//nie skompiluje siê, brak construktora


	return 0;
}