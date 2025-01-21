#include <iostream>
#include <format>

template <typename T>
class Storage
{
private:
	T m_value{};
public:
	explicit Storage(T value) : m_value{value}{}

	void print()
	{
		std::cout << m_value << '\n';
	}
};

//this is a specialized member function definitoon
//explicit function specialiations are not implicitly inline,
//so it needs to be made inline if put in a header file
template<>
void Storage<double>::print()
{
	std::cout << std::format("{}", m_value) << '\n';
}

int main()
{
	//define some storage units
	Storage i{ 5 };
	Storage d{ 6.7 };  // will cause Storage<double> to be implicitly instantiated

	//Print out some values
	i.print();  // calls Storage<int>::print() (instantiated from Storage<T>)
	d.print();  //calls Storage<double>::print (called from explicit specialization of 
				//Storage<double>::print	

	return 0;
}