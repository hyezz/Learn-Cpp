#include <iostream>

using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	// 원래 return type 다르면 override 불가능한데, 상속 관계의 클래스는 return 가능
	virtual B* getThis()
	{
		cout << "B::getThis()" << endl;
		return this; 
	}
};

int main()
{
	A a;
	B b;

	A& ref = b;
	b.getThis()->print();	// B
	ref.getThis()->print();	// A

	cout << typeid(b.getThis()).name() << endl;		// class B *
	cout << typeid(ref.getThis()).name() << endl;	// class A *

	return 0;
}