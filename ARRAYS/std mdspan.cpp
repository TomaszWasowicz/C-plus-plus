/*

Introduced in C++23, std::mdspan is a modifiable view that provides 
a multidimensional array interface for a contiguous sequence of elements. 
By modifiable view, we mean that a std::mdspan is not just a read-only view 
(like std::string_view) -- if the underlying sequence of elements is non-const, 
those elements can be modified.

*/

#include <iostream>
#include <array>
#include <mdspan>

template<typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row* Col>;

int main()
{
	// one dimentional array - 3 rows, 4 columns

	ArrayFlat2d<int, 3, 4> arr{ 1,2,3,4,5,6,7,8,9,10,11,12 };

	// two dimensional span into one dimensional aray
	//we must pass std::mdspan a pointer to the sequence of elemets
	// which we can do via the data() member function of std::array or std::vector

	std::mdspan mdView{ arr.data(), 3,4 };
	

	//print array dimensions
	//std::mdspan calls these extents
	std::size_t rows{ mdView.extent().extent(0) };
	std::size_t cols{ mdView.extent().extent(1) };
	std::cout << "Rows: " << rows << '\n';
	std::cout << "Cols: " << cols << '\n';

	//print array in 1d
	// the data_hadle() member gives a pointer to the sequence of elements
	//which can then be indexed with std::mdspan

	for (std::size_t i = 0; i < mdView.size(); ++i)
		std::cout << mdView.data_handle()[i] << ' ';
	std::cout << '\n';

	//print array in 2d
	//use the multidimentional [] to access elements

	for (std::size_t row = 0; row < rows; ++row)
	{
		for (std::size_t col = 0; col < cols; ++col)
			std::cout << mdView[row, col] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';

	return 0;
}