#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("01234567");
	// c-style 문자열에는 null character가 하나 숨어있음
	// string은 내부적으로 길이를 직접 가지고 있어서 null을 별도로 보관하지 않음
	//string my_str;
	//string my_str("");

	cout << boolalpha;
	cout << my_str.empty() << endl;		// false
	cout << my_str.size() << endl;		// 8
	cout << my_str.length() << endl;	// 8
	cout << my_str.capacity() << endl;	// 15 (새로 데이터가 추가될 가능성을 고려해서 memory reallocation 안하려고 여분의 용량 확보)
	cout << my_str.max_size() << endl;	// 2147483647

	my_str.reserve(1000);	// 미리 용량 확보
	cout << my_str.capacity() << endl;	// 1007

	return 0;
}