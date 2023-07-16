#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:

	//nie statyczna inicjalizacja funkcji
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:

	Ball() = default;		//defaultowy konstruktor

	Ball(double radius):m_radius{radius}{}  //KOnstruktor ktory przyjmie tylko radius

	Ball(std::string_view color) : m_color{ color } {}; //konstruktor ktory przyjmie tylko color

	Ball(std::string_view color, double radius) : m_color{ color }, m_radius{ radius } {}; // przyjmie oba argumenty

	void print() { std::cout << "color: " << m_color << ", radius: " << m_radius << '\n'; }

};

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" }; 
	blue.print();

	Ball thirty{ 30.0 };
	thirty.print();

	Ball white_and_forty{ "white", 40.0 };
	white_and_forty.print();

	return 0;
}