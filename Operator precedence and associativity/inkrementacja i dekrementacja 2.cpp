
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';
    int y = ++x; // x is incremented to 6, 
                 //x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';

    int z{ 5 };
    std::cout << z << '\n';
    int w = z++; // z is incremented to 6, copy of original 
                //z is evaluated to the value 5, and 5 is assigned to w

    std::cout << z << ' ' << w << '\n';



    return 0;
}