#include <iostream>
#include <string>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(const std::string& name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

class Department
{
private:
    const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
    Department(const Teacher& teacher)
        : m_teacher{ teacher }
    {
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher bob{ "Bob" }; // create a teacher

    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department department{ bob };

    } // department goes out of scope here and is destroyed

    // bob still exists here, but the department doesn't

    std::cout << bob.getName() << " still exists!\n";

    return 0;
}