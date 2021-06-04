#include <iostream>

using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived : public Base
//class Derived : protected Base
//class Derived : private Base
{
public:
	Derived()
	{
		m_public = 123;		// Base::m_public, this->m_public
		m_protected = 123;
		//m_private = 123;
	}
};

// Class Derived : private Base일 경우 GrandChild에서 접근 불가
class GrandChild : protected Derived
{
public:
	GrandChild()
	{
		//Derived::m_public;
		//Derived::m_protected;
		//Derived::m_private;
	}
};

int main()
{
	Base base;
	//base.m_public = 123;
	//base.m_protected = 123;

	Derived derived;
	//derived.m_public;
	//derived.m_protected;
	//derived.m_private;

	return 0;
}