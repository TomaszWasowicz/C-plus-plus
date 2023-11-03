//Curiously Recurring Template Pattern - CRTP

template<class T>
class Mixin
{
	//Mixin<T> can use template parameter T to access members of Derived
	//via (static_cast<T*>(this))
};

class Derived : public Mixin<Derived>
{

};