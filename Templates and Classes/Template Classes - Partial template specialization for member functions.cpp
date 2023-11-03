#include <iostream>

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
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << '\n';
	}
};

template <int size> // size is the expression parameter
class StaticArray<double, size>
{
private:
	// The expression parameter controls the size of the array
	double m_array[size]{};

public:
	double* getArray() { return m_array; }

	double& operator[](int index)
	{
		return m_array[index];
	}
	void print()
	{
		for (int i{ 0 }; i < size; ++i)
			std::cout << std::scientific << m_array[i] << ' ';
		std::cout << '\n';
	}
};

int main()
{
	// declare an integer array with room for 6 integers
	StaticArray<int, 6> intArray{};

	// Fill it up in order, then print it
	for (int count{ 0 }; count < 6; ++count)
		intArray[count] = count;

	intArray.print();

	// declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray{};

	for (int count{ 0 }; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);

	doubleArray.print();

	return 0;
}