#include <iostream>

using namespace std;

class Base
{
public:
	//FunctionPointer* __vptr;
	virtual void fun1() {};
	void fun2() {};
};

class Der : public Base
{
public:
	//FunctionPointer* __vptr;
	void fun1() {};
	void fun3() {};
};

int main()
{
	// virtual function pointer 생성
	cout << sizeof(Base) << endl;	// 4 (virtual function 없으면 1 Byte)
	cout << sizeof(Der) << endl;	// 4

	return 0;
}