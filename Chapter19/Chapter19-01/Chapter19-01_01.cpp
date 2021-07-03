#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};

int main()
{
	// lamda-introducer				: []
	// lamda-parameter-declaration	: ()
	// lamda-return-type-clause		: -> return type
	// compound-statement			: {}
	auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };

	func(123);
	
	// function name ���� �� lambda function ���� ����
	[](const int& i) -> void { cout << "Hello, World!" << endl; }(1234);

	{
		string name = "JackJack";
		[&]() {cout << name << endl; }();	// [&] : reference ���, [this] : Ŭ������ ���, [=] : copy
	}

	// STL�� �Բ� ���
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// �Լ� �����͸� for_each() �Ķ���ͷ� ����ϴ� ��ó�� ����
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });	// �̷��� ����ϴ� ���� ��ȣ

	cout << []() -> int {return 1; }() << endl;

	// function : function ptr ü��ȭ��Ų ��
	function<void(int)> func3 = func2;
	func3(123);

	function<void()> func4 = bind(func3, 456);
	func4();

	// placeholders : parameter �������� �� ���
	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		auto f = bind(&Object::hello, &instance, placeholders::_1);	// member function ptr, instance ptr, placeholders::_parameter num

		f(string("World"));

		auto f2 = bind(&goodbye, placeholders::_1);	// function ptr, placeholders::_parameter num

		f2(string("World"));
	}

	return 0;
}