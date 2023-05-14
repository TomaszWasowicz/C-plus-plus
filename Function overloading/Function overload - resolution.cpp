#include <iostream>

void print(int x)
{
    std::cout << x;
}

void print(double d)
{
    std::cout << d;
}

int main()
{
    print('a'); // char does not match int or double
    print(5l); // long does not match int or double

    return 0;
}

// kompilator znalazl 2 funkcje ktora pasuja do wzorca wywolania

//rozwiazuje to static_cast<int>()