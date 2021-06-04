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
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value)
		: Base(value)
	{}

	// Derived Ŭ�������� ��� �����ϰ�
	using Base::m_i;

	// Derived Ŭ�������� ��� �Ұ����ϰ�
private:
	using Base::print;	// do not add () : �Լ� �̸��� ������ �ȴ�
	void print() = delete;
};

int main()
{
	Base base(5);
	base.print();

	Derived derived(7);

	derived.m_i = 1024;
	//derived.print();

	return 0;
}