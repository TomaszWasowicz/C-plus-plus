#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAdress(const std::string* ptr)
{
    std::cout << *ptr << '\n';
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAdress(&str); //pass str by adress, does not make a copy of str

    std::string* ptr{ &str }; //define a pointer varaible holding the adress of str
    printByAdress(ptr); //pass str by adress, does not make a copy of str

    return 0;
} 