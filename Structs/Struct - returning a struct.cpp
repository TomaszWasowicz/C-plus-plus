#include <iostream>

struct Point3d
{
    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };
};

Point3d getZeroPoint()
{
    return Point3d{2.3, 0.0, 0.0};
}

int main()
{
    Point3d zero{ getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}