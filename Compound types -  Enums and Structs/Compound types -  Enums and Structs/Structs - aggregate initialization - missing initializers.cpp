struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee joe{ 2, 28 }; // joe.wage will be value-initialized to 0.0

    return 0;
}