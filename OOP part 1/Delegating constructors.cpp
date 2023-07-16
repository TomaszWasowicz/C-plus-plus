#include <iostream>

class Foo
{
private:

public:
    Foo()
    {
        std::cout << "A!" << '\n';
    }

    Foo(int value) : Foo{} // use Foo() default constructor to do A
    {
        std::cout << "B!" << '\n';
    }

};

int main()
{
    Foo f1{ 4 }; // A! and then B!
    Foo f2{}; // A!


    return 0;
}