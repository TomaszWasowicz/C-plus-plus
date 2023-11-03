#include <cassert> // for assert()
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

class IntArray
{
private:
    int m_length{};
    std::unique_ptr<std::vector<int>> m_data{};

public:
    IntArray() = default;

    explicit IntArray(int length)
        : m_length{ length }
        , m_data{ std::make_unique<std::vector<int>>(length)}{}


    //allow IntArray to be initilized via list initialisation
    explicit IntArray(std::initializer_list<int> values)
        : m_length{ static_cast<int>(values.size()) },
        m_data{ std::make_unique<std::vector<int>>(values) }
    {
    }

    IntArray(const IntArray&) = delete; // to avoid shallow copies
    IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return (*m_data)[index];
    }

    int getLength() const { return m_length; }

    bool operator==(const IntArray& other) const
    {
        return m_length == other.m_length && m_data == other.m_data;
    }
};

int main()
{
    // What happens if we try to use an initializer list with this container class?
    
    IntArray array{ 5, 4, 3, 2, 1 }; // initializer list

    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    return 0;
}