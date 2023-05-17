#include <iostream>

enum Animal
{
    cat = -3,
    dog,         // assigned -2
    pig,         // assigned -1
    horse = 5,
    giraffe = 5, // shares same value as horse
    chicken,      // assigned 6
};

int main()
{
    std::cout << cat << '\n';   //-3



    return 0;
}