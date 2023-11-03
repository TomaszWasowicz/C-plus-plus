#include <iostream>
#include <string>

template <typename T>
class Storage
{
private:
	T m_value{};
public:
	Storage(T value): m_value {value}{}

	~Storage() {};

	void print()
	{
		std::cout << m_value << '\n';
	}
};

template <>
Storage<char*>::Storage(char* const value)
{
	if (!value)
		return;

	// Figure out how long the string in value is
	int length{ 0 };
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator

	// Allocate memory to hold the value string
	m_value = new char[length];

	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

template <>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

int main()
{
	//Dynamically allocate a temporary string
	std::string s;

	//Ask the user for their name
	std::cout << "Enter your name: ";
	std::cin >> s;

	//Store the name
	Storage<char*> storage(s.data());

	storage.print(); //Prints our name

	s.clear();      //clear the std::string

	storage.print();


	return 0;

}