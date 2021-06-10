#include <iostream>

using namespace std;

class Base
{
public:
	Base() {}

	// friend�� ��� �Լ��� �ƴϿ��� ���� override �Ұ���
	friend ostream& operator << (ostream& out, const Base& b)
	{
		return b.print(out);
	}

	// ����� ���ӹ��� virtual function ����
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

	// sub class���� override
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