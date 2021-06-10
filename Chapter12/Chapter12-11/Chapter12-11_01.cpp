#include <iostream>

using namespace std;

class Base
{
public:
	Base() {}

	// friend는 멤버 함수가 아니여서 직접 override 불가능
	friend ostream& operator << (ostream& out, const Base& b)
	{
		return b.print(out);
	}

	// 기능을 위임받은 virtual function 구현
	virtual ostream& print(ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	// sub class에서 override
	virtual ostream& print(ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << '\n';

	Derived d;
	cout << d << '\n';

	Base& bref = d;
	cout << bref << '\n';

	return 0;
}