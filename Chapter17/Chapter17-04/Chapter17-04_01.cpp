#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");

	// ���� ����
	// [] : �����ս� good, at() : ������ good
	{
		cout << my_str[0] << endl;	// a
		cout << my_str[3] << endl;	// d

		my_str[3] = 'Z';

		try
		{
			//my_str[100] = 'X';	// runtime error (operator [] overloading ����ó�� ������)
			my_str.at(100) = 'X';	// throw exception
		}
		catch (exception& e)
		{
			cout << e.what() << endl;	// invalid string position
		}

		cout << my_str << endl;
	}

	// string -> c-style array ��ȯ
	{
		// 1) c_str(), data() : �� ���� null character �߰� (c-styleó�� ��� ����)
		cout << my_str.c_str() << endl;

		//const char* arr = my_str.c_str();
		const char* arr = my_str.data();	// c_str()�� ���
		cout << (int)arr[6] << endl;	// 103
		cout << (int)arr[7] << endl;	// 0

		// 2) copy() : buffer�� ���� (null character �ڵ����� �� ����)
		char buf[20];

		my_str.copy(buf, 5, 1);	// 1��°���� 5��ŭ ����

		buf[5] = '\0';	// null character �߰�

		cout << buf << endl;
	}

	return 0;
}