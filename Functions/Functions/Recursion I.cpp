#include <iostream>

void countDown(int count)
{
    std::cout << "push " << count << '\n';
    countDown(count - 1); // countDown() calls itself recursively
}

int main()
{
    countDown(5);

    return 0;
}