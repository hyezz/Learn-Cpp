#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string ToString(T x)
{
	ostringstream osstream;
	osstream << x;	// stringstream�� x ����
	return osstream.str();	// ���� x�� string ���� �ٲ㼭 ����
}

template <typename T>
bool FromString(const string& str, T& x)
{
	istringstream isstream(str);	// string���� stringstream �ʱ�ȭ
	return (isstream >> x) ? true : false;
}

int main()
{
	// �������� ������
	{
		string my_string("my string");			// c-style ���ڿ� �ʱ�ȭ
		//const char* my_string = "my string";
		string second_string(my_string);		// ���� ����
		string third_string(my_string, 3, 5);	// 3��°���� 5��ŭ ����
		string fourth_string(10, 'A');			// 'A'�� 10��ŭ ����

		vector<char> vec;
		for (auto e : "Today is a good day.")	// iterator �ʱ�ȭ
			vec.push_back(e);
		string fifth_string(vec.begin(), vec.end());
		string sixth_string(vec.begin(), find(vec.begin(), vec.end(), 'y'));	// 'y' ã�Ƽ� �� ��ġ���� ����

		cout << my_string << endl;
		cout << second_string << endl;
		cout << third_string << endl;	// strin
		cout << fourth_string << endl;	// AAAAAAAAAA
		cout << fifth_string << endl;	// Today is a good day.
		cout << sixth_string << endl;	// Toda
	}
	
	// ����ȯ
	{
		// ���� -> ���ڿ�
		string my_str(to_string(1004));	// ���� -> ���ڿ�
		my_str += to_string(128);

		string my_str2(ToString(3.141592));	// T -> string

		string my_str3("Hello");	// FromString �Ұ���

		cout << my_str << endl;
		cout << my_str2 << endl;

		// ���ڿ� -> ����
		int i = stoi(my_str);	// string -> int
		float f = stof(my_str);	// string -> float

		cout << i << endl;
		cout << f << endl;

		double d;
		if (FromString(my_str2, d))	// string -> T
		//if (FromString(my_str3, d))
			cout << d << endl;
		else
			cout << "Cannot convert string to double" << endl;

		cout << my_str2 << endl;
	}

	return 0;
}