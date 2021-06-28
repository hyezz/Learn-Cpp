#include <iostream>
#include <string>
#include <iomanip>	// input/output manipulators

using namespace std;

int main()
{
	{
		cout << "Enter a number" << endl;

		int i;
		cin >> i;

		cout << i << endl;
	}

	// stream: buffer�� �ӽ������� ����� ������ �Ϻ� �������� ���
	{
		char buf[10];

		cin >> buf;	// buf size���� ũ�� runtime error
		cout << buf << endl;

		// setw() : �ִ� 5���ڸ� �޵��� ���� (�������� null)
		cin >> setw(5) >> buf;	// abcdefghij
		cout << buf << endl;	// abcd

		cin >> setw(5) >> buf;
		cout << buf << endl;	// efgh

		cin >> setw(5) >> buf;
		cout << buf << endl;	// ij
	}

	{
		char ch;

		while (cin >> ch)	// ��ĭ ����
			cout << ch;

		while (cin.get(ch)) // ��ĭ
			cout << ch;
	}
	
	// char buffer �Է�
	{
		char buf[5]; // size ������ ���� array

		//cin.get(buf, 5);
		cin.getline(buf, 5);	// line ���� �Է�, �ٹٲ� character���� ���� ����

		//cout << buf << endl;
		cout << cin.gcount() << " " << buf << endl;

		//cin.get(buf, 5);
		cin.getline(buf, 5);

		//cout << buf << endl;
		cout << cin.gcount() << " " << buf << endl;
	}

	// string buffer �Է�
	{
		string buf;

		getline(cin, buf);
		cout << cin.gcount() << " " << buf << endl;	// string buffer ����ϸ� gcount = 0
	}

	// cin.ignore(2)	: �Է¹��� �� 2���� ����
	// cin.peek()		: buffer���� ���� ���� �о�� ���� �鿩�ٺ��� (������ ����)
	// cin.unget()		: �������� ���� ���ڸ� buffer�� ���� �������
	// cin.putback('A') : 'A'�� buffer�� �������
	{
		char buf[1024];

		//cin.ignore(2);
		//cout << (char)cin.peek() << endl;
		//cin.unget();
		cin.putback('A');

		cin >> buf;
		cout << buf << endl;
	}

	return 0;
}