#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	// os << "Hello" : buffer�� ��� ������
	// os.str("Hello") : buffer ��ü
	{
		stringstream os;

		os << "Hello, World!";	// << : insertion operator, >> : extraction operator
		os << "Hello, World!2" << endl;	// endline ���� ����
		//os.str("Hello, World!\n");	// �ٹٲ� ���� ����

		string str;

		//os >> str;	// Hello, (��ĭ���� �ڸ�)
		str = os.str();	// string ��°�� ������
		cout << str << endl;
		//cout << os.str() << endl;
	}
	
	{
		stringstream os;

		// buffer�� ����

		// 1) ���ڿ�
		//os << "12345 67 89";

		// 2) ���ڸ� ���ڿ��� ����
		int i = 12345;
		double d = 67.89;

		os << i << d;
		//os << i << " " << d;

		// buffer ���

		// 1) ���ڿ� (��ĭ �������� ����)
		string str1;
		string str2;

		//os >> str1 >> str2;
		//cout << str1 << "|" << str2 << endl;

		// 2) buffer�� ���ڷ� ��� 
		int i2;
		double d2;

		os >> i2 >> d2;
		cout << i2 << "|" << d2 << endl;
	}

	// stringstream �ʱ�ȭ
	{
		stringstream os;

		os << "12345 67.89";

		// os.str() overloading
		os.str("");		// �Ķ���� ���� ���� buffer ���
		cout << os.str() << endl;	// �Ķ���� ���� ���� ����

		// stringstream �ʱ�ȭ
		os.str("");
		os.str(string());
		os.clear();	// state �ʱ�ȭ (stringstream �ʱ�ȭ X)

		cout << os.str() << endl;
	}

	return 0;
}