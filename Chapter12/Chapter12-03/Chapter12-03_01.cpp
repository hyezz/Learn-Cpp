#include <iostream>

using namespace std;

class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
	// parameter, function name, return type, const 실수하지 않도록 override 명시 (컴파일 오류 발생)
	void print(int x) override { cout << "B" << endl; }
};

class C : public B
{
public:
	// final 추가하면 하위 클래스에서 override 불가능
	virtual void print() final { cout << "C" << endl; }
};

class D : public C
{
public:
	//virtual void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	B b;
	C c;

	A& ref = b;
	ref.print(1);

	return 0;
}