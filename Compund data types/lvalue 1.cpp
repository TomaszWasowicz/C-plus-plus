/*
An lvalue is an expression that evaluates to a function 
or object that has an identity. 
An object or function has an identity if it has an identifier 
(such as a variable or named function) or an identifiable memory address 
(one that can be retrieved using operator&). 
Identifiable objects persist beyond the scope of the expression.
*/

#include <iostream>

int main()
{
    int x{};
    const double d{};

    std::cout << x << '\n'; // x is a modifiable lvalue expression
    std::cout << d << '\n'; // d is a non-modifiable lvalue expression

    return 0;
}