#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>

int main()
{
    constexpr std::array<int, 5> array{ 1,2,3,4,5 };

    // Good: Instead, we can store the lambda in a named variable and pass it to the function.
    auto isEven{[](int i)
      {
        return ((i % 2) == 0);
      }
    };

    return std::all_of(array.begin(), array.end(), isEven);

}
/*


[ captureClause ] ( parameters ) -> returnType
{
    statements;
}
 

*/