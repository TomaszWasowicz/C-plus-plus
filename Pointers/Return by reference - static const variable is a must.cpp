#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName{ "Calculator" }; // must be static, for the refernce not to dangle

    return s_programName;                                   //variable must be static to live outside fucntion
}

int main()
{
    std::cout << "This program is named " << getProgramName();

    return 0;
}