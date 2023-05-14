#include <iostream>
#include <string>

const int& getNextId()
{
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

int main()
{
    const int id1{ getNextId() }; // BRAK & po int
    
    // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
    
    const int id2{ getNextId() }; // BRAK & po int
    
    // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

    std::cout << id1 << id2;

    return 0;
}