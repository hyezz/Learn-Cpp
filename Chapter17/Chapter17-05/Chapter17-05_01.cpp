#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 대입 assign()
	{
		string str1("one");

		string str2;
		str2 = str1;
		str2 = "two";
		str2.assign("two").append(" ").append("three ").append("four");	// Chaining

		cout << str2 << endl;	// two three four
	}
	
	// 교환 swap()
	{
		string str1("one");
		string str2("two");

		cout << str1 << " " << str2 << endl;	// one two

		swap(str1, str2);

		cout << str1 << " " << str2 << endl;	// two one

		str1.swap(str2);

		cout << str1 << " " << str2 << endl;	// one two
	}

	// 덧붙이기 append()
	{
		string str1("one");
		string str2("two");
		
		str1.append("three");
		str1.push_back('A');	// char만 가능
		str1 += "three";

		cout << str1 << endl;	// onethreeAthree

		str1 = str2 + "four";

		cout << str1 << endl;	// twofour
	}

	// 삽입 insert()
	{
		string str("aaaa");

		str.insert(2, "bbb");	// 2번째에 "bbb" 삽입

		cout << str << endl;	// aabbbaa
	}

	return 0;
}