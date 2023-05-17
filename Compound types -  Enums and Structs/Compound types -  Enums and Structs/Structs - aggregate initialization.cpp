struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee frank = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee robert(3, 45, 62500.0);  // direct initialization using parenthesized list (C++20)
    Employee joe{ 2, 28, 45000.0 };     // list initialization using braced list (preferred)

    return 0;
}