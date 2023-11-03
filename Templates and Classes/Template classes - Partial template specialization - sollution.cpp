#include <iostream>
#include <cstring>

template <typename T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}
};

template <typename T, int size>
void print(StaticArray<T, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
}

// overload of print() function for partially specialized StaticArray<char, size>
template <int size> // size is still a templated expression parameter
void print(StaticArray<char, size>& array) // we're explicitly defining type char here
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
}

int main()
{

	// declare a char array
	StaticArray<char, 14> char14{};

	const char* source = "Hello, world!";

	strcpy_s(char14.getArray(), 14, source);

	// Print the array
	print(char14);  //Hello, world!
	



	// declare a char array
	StaticArray<char, 12> char12{};

	const char* source2 = "Hello, mom!";

	strcpy_s(char12.getArray(), 12, source2);

	// Print the array
	print(char12);  //Hello, mom!

	return 0;
}