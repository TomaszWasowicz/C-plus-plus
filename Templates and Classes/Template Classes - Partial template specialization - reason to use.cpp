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

int main()
{
	// declare an int array
	StaticArray<int, 4> int4{};
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;

	// Print the array
	print(int4);  // 0, 1, 2, 3




	// declare a char array
	StaticArray<char, 14> char14{};

	const char* source = "Hello, world!";
	strcpy_s(char14.getArray(), 14, source);

	// Print the array
	print(char14); // H e l l o ,  w o r l d ! - too much space between 'hello' and 'world'



	return 0;
}