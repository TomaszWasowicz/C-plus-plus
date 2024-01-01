#include <iostream>
using namespace std;

int main() {
    // declare variables
    int a = 12;
    int b = 25;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int c = a << 1;   // 12 * 2^1
    int d = b >> 1;     // 25 / 2^1

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    



    cout << "a & b = " << (a & b) << endl;


    return 0;
}