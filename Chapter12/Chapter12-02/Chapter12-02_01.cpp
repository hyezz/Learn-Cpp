#include <iostream>

using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	virtual void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	a.print();	// A

	B b;
	b.print();	// B

	C c;
	c.print();	// C

	D d;
	d.print();	// D

	A& ref = b;
	ref.print();	// B

	return 0;
}