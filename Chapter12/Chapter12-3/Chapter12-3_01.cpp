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
	// parameter, function name, return type, const �Ǽ����� �ʵ��� override ��� (������ ���� �߻�)
	void print(int x) override { cout << "B" << endl; }
};

class C : public B
{
public:
	// final �߰��ϸ� ���� Ŭ�������� override �Ұ���
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