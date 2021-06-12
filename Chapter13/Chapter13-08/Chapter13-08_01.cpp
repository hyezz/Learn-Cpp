#include <iostream>

using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{}

	template<typename TT> // doSomething() 에서만 적용되는 template parameter
	//void doSomething()
	void doSomething(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;	// casting
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();
	a_int.doSomething(123.4);	// int double
	a_int.doSomething('a');		// int char

	A<char> a_char('A');
	a_char.print();
	//a_char.doSomething<int>();	// 함수 파라미터가 없는 경우에도 직접 instantiation 가능
	a_char.doSomething(int());
	a_char.doSomething(char());
	
	return 0;
}