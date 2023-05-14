#include <iostream>

void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count - 1);

    std::cout << "pop " << count << '\n';
}

int main()
{
    countDown(5);
    return 0;
}