struct Rectangle
{
    double length{};
    double width{};
};

int main()
{
    const Rectangle unit{ 1.0, 1.0 };
    const Rectangle zero{ }; // value-initialize all members

    return 0;
}

//  conts structs must be (even zero ) initilized
