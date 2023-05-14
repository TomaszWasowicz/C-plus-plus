#include <iostream>

using namespace std;

struct C
{
    C() { printf("Cc"); }
    ~C() { printf("Cd"); }
    void test() 
    {
        cout << "a";                        
    };

};
struct D : public C
{
    D() { printf("Dc"); }
    ~D() { printf("Dd"); }
    void test() 
    {
        cout << "b";
    };
};

int main()
{

    new D();            // Cc Dc

    C* c = new D();     // CC Dc

    c->test();          // a

}


//Cc Dc Cc Dc a - bez spacji




