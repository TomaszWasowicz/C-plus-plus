class Base
{
public:
    int m_public{};

protected:
    int m_protected{};

private:
    int m_private{};
};

class Pri : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pri()
    {
        m_public = 1; // okay: m_public is now private in Pri
        m_protected = 2; // okay: m_protected is now private in Pri
        m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};

class D2 : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private
    // Protected inherited members become private
    // Private inherited members stay inaccessible
public:
    int m_public2{};
protected:
    int m_protected2{};
private:
    int m_private2{};
};

class D3 : public D2
{ 
    // Public inheritance means:
    // Public inherited members stay public
    // Protected inherited members stay protected
    // Private inherited members stay inaccessible
public:
    int m_public3{};
protected:
    int m_protected3{};
private:
    int m_private3{};
};

int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    base.m_protected = 2; // not okay: m_protected is protected in Base
    base.m_private = 3; // not okay: m_private is private in Base

    Pri pri;
    pri.m_public = 1; // not okay: m_public is now private in Pri
    pri.m_protected = 2; // not okay: m_protected is now private in Pri
    pri.m_private = 3; // not okay: m_private is inaccessible in Pri

    return 0;
}