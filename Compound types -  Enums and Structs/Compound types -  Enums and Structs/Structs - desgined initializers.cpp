struct Foo
{
    int a{};
    int b{}; // just added
    int c{};
};

int main()
{
    Foo f{ 1, 3 }; // now, f.a = 1, f.b = 3, f.c = 0
}