#include<iostream>
#include<format>

//primary template must come first
//In order to specialize a template, the compiler first must have seen 
// a declaration for the primary template

template<typename T>
void print(const T& t)
{
	std::cout << t << '\n';
}

// A full specialization of primary template print<T> for type double
//Full specialization are not implicitly inline,
//so make this inline if put it in a header file

template<>	//full specialziation, template parameter declaration containing no template parameters
void print<double>(const double& d)
{
	std::cout << std::format("{:.2e}\n", d);
}

int main()
{
	print(5);
	print(6.8);


	return 0;
}