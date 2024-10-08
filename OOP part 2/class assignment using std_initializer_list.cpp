//First, the compiler will note that an assignment function taking 
// a std::initializer_list doesn’t exist.
// Next it will look for other assignment functions it could use, 
// and discover the implicitly provided copy assignment operator. 
// However, this function can only be used if it can convert the initializer list into an IntArray.
// Because{ 1, 3, 5, 7, 9, 11 } is a std::initializer_list, 
// the compiler will use the list constructor to convert the initializer list into a temporary IntArray.
// Then it will call the implicit assignment operator, 
// which will shallow copy the temporary IntArray into our array object.
// At this point, both the temporary IntArray’s m_data and array->m_data point 
// to the same address(due to the shallow copy).
// At the end of the assignment statement, the temporary IntArray is destroyed.
// That calls the destructor, which deletes the temporary IntArray’s m_data.
// This leaves array->m_data as a dangling pointer.
// When you try to use array->m_data for any purpose
// (including when array goes out of scope and the destructor goes to delete m_data), 
// you’ll get undefined behavior.



#include <cassert>  //for assert()
#include <initializer_list>  //for std::initalizer_list
#include <iostream>

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length) : 
		m_length{ length }, 
		m_data{ new int [static_cast<std::size_t>(length)] {} } {}

	IntArray(std::initializer_list<int> list) :
		IntArray(static_cast<int>(list.size()))
	{

		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const
	{
		return m_length;
	}

};

int main()
{
	IntArray array{};
	array = { 1,3,5,7,9,11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}