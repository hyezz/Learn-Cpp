#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ���� assign()
	{
		string str1("one");

		string str2;
		str2 = str1;
		str2 = "two";
		str2.assign("two").append(" ").append("three ").append("four");	// Chaining

		cout << str2 << endl;	// two three four
	}
	
	// ��ȯ swap()
	{
		string str1("one");
		string str2("two");

		cout << str1 << " " << str2 << endl;	// one two

		swap(str1, str2);

		cout << str1 << " " << str2 << endl;	// two one

		str1.swap(str2);

		cout << str1 << " " << str2 << endl;	// one two
	}

	// �����̱� append()
	{
		string str1("one");
		string str2("two");
		
		str1.append("three");
		str1.push_back('A');	// char�� ����
		str1 += "three";

		cout << str1 << endl;	// onethreeAthree

		str1 = str2 + "four";

		cout << str1 << endl;	// twofour
	}

	// ���� insert()
	{
		string str("aaaa");

		str.insert(2, "bbb");	// 2��°�� "bbb" ����

		cout << str << endl;	// aabbbaa
	}

	return 0;
}