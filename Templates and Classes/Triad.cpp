#include <iostream>
#include <string>

template <typename T1, typename T2, typename T3>
class Triad {
private:
    T1 first_;
    T2 second_;
    T3 third_;

public:
    Triad(T1 first, T2 second, T3 third) : first_(first), second_(second), third_(third) {}

    T1 first() const { return first_; }
    T2 second() const { return second_; }
    T3 third() const { return third_; }

    void print() const;

};

template <typename T1, typename T2, typename T3>
void Triad<T1, T2, T3>::print() const {
    std::cout << "[" << first_ << ", " << second_ << ", " << third_ << "]" << std::endl;
}

int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';    

    using namespace std::literals::string_literals;
    const Triad<int, double, std::string> t2{ 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}

