#include <iostream>
#include <vector>
#include <functional>

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

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

// reference 생략하면 파라미터 복사되면서 객체 잘림
void doSomething(Base b)
{
	b.print();
}

int main()
{
	// obejct slicing 1
	Derived d;
	//Base& b = d;
	Base b = d;
	b.print();

	// object slicing 2
	doSomething(d);

	Base base;
	Derived derived;

	// object slicing 3
	vector<Base> my_vec;
	my_vec.push_back(base);
	my_vec.push_back(derived);

	for (auto& ele : my_vec)
		ele.print();

	// 1) pointer 사용
	vector<Base*> my_vec2;
	my_vec2.push_back(&base);
	my_vec2.push_back(&derived);

	for (auto& ele : my_vec2)
		ele->print();

	// 2) reference wrapper 사용 (vector에 reference 넣을 수 없음)
	vector<reference_wrapper<Base>> my_vec3;
	my_vec3.push_back(base);
	my_vec3.push_back(derived);

	for (auto& ele : my_vec3)
		ele.get().print();

	return 0;
}