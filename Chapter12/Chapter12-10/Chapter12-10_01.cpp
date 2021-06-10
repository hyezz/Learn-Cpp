#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}

};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}

};

int main()
{
	Derived1 d1;
	Base* base = &d1;

	// Dynamic cast
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl;

	base_to_d1->m_j = 256;
	cout << d1.m_j << endl;

	auto* base_to_d2 = dynamic_cast<Derived2*>(base);
	if (base_to_d2 != nullptr)
		base_to_d2->print();
	else
		cout << "Failed" << endl;	// 런타임 에러 체크 (불가능한 경우 nullptr 넣어줌)

	// Static cast
	auto* base_to_d3 = static_cast<Derived1*>(base);
	if (base_to_d3 != nullptr)
		base_to_d3->print();
	else
		cout << "Failed" << endl;

	auto* base_to_d4 = static_cast<Derived2*>(base);
	if (base_to_d4 != nullptr)
		base_to_d4->print();	// 런타임 에러 체크 안함
	else
		cout << "Failed" << endl;

	return 0;
}