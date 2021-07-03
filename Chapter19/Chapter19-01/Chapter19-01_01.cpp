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
	
	// function name 없을 때 lambda function 진가 발휘
	[](const int& i) -> void { cout << "Hello, World!" << endl; }(1234);

	{
		string name = "JackJack";
		[&]() {cout << name << endl; }();	// [&] : reference 사용, [this] : 클래스의 멤버, [=] : copy
	}

	// STL과 함께 사용
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// 함수 포인터를 for_each() 파라미터로 사용하는 것처럼 보임
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });	// 이렇게 사용하는 것을 선호

	cout << []() -> int {return 1; }() << endl;

	// function : function ptr 체계화시킨 것
	function<void(int)> func3 = func2;
	func3(123);

	function<void()> func4 = bind(func3, 456);
	func4();

	// placeholders : parameter 여러개일 때 사용
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