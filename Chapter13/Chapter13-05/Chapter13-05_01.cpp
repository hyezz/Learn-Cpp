#include <iostream>
#include <array>

using namespace std;

template<typename T>
class A
{
public:
	A(const T& input)
	{}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

template<>
class A<char>
{
public:
	A(const char& temp)
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	//A a_int(1); // C++17에서는 컴파일 가능
	A<int>		a_int(1);
	A<double>	a_double(3.14);
	A<char>		a_char('A');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	//a_char.test();	// 함수 호출 불가

	return 0;
}