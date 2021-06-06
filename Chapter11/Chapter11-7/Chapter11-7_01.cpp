#include <iostream>

using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	void print()
	{
		Base::print();	// super class 함수 호출
		cout << "I'm derived " << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& b)
	{
		cout << static_cast<Base>(b);	// super class operator 호출
		out << "This is Derived output" << endl;
		return out;
	}
};

int main()
{
	Base base(5);
	base.print();
	cout << base;

	Derived derived(7);
	derived.print();
	cout << derived;

	return 0;
}