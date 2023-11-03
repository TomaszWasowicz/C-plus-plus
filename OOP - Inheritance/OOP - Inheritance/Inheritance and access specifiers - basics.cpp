class Base
{
public:
	int m_public{}; //accessed by anybody

protected:
	int m_protected{}; // accessed by Base members, friends, derived classed

private:
	int m_private{}; //accessed by Base members and friends ( but not derived classes )
};

class Derived : public Base
{
	Derived()
	{
		m_public = 1; //allowed: can access public base members from derived class

		m_protected = 2; // allowed: can access protected base members from derived class

		m_private = 3; // NOT ALLOWED: cannot access private base members from derived class
	}
};

int main()
{
	Base base;
	base.m_public = 1; //allowed: can access public members from outside the class
	base.m_protected = 2; // NOT allowed: cannot access protected members from outside the class
	base.m_private = 3; // NOT allowed: cannot access private members from outside of the class

	return 0;
}