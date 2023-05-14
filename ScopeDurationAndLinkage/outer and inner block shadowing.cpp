#include <iostream>

int main()
{ // outer block
    int apples{ 5 }; // here's the outer block apples

    { // nested block
        // apples refers to outer block apples here
        std::cout << apples << '\n'; // print value of outer block apples

        // no inner block apples defined in this example
        int apples{ 0 };  // if this will be undefined, the apples will be 5,10,10

        apples = 10; // this applies to outer block apples

        std::cout << apples << '\n'; // print value of outer block apples
    } // outer block apples retains its value even after we leave the nested block

    std::cout << apples << '\n'; // prints value of outer block apples

    return 0;
} // outer block apples destroyed