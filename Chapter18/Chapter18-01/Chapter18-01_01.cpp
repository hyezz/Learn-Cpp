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

	// stream: buffer에 임시적으로 저장된 정보를 일부 꺼내오는 방식
	{
		char buf[10];

		cin >> buf;	// buf size보다 크면 runtime error
		cout << buf << endl;

		// setw() : 최대 5글자만 받도록 제한 (마지막은 null)
		cin >> setw(5) >> buf;	// abcdefghij
		cout << buf << endl;	// abcd

		cin >> setw(5) >> buf;
		cout << buf << endl;	// efgh

		cin >> setw(5) >> buf;
		cout << buf << endl;	// ij
	}

	{
		char ch;

		while (cin >> ch)	// 빈칸 무시
			cout << ch;

		while (cin.get(ch)) // 빈칸
			cout << ch;
	}
	
	// char buffer 입력
	{
		char buf[5]; // size 고정된 정적 array

		//cin.get(buf, 5);
		cin.getline(buf, 5);	// line 단위 입력, 줄바꿈 character까지 같이 읽음

		//cout << buf << endl;
		cout << cin.gcount() << " " << buf << endl;

		//cin.get(buf, 5);
		cin.getline(buf, 5);

		//cout << buf << endl;
		cout << cin.gcount() << " " << buf << endl;
	}

	// string buffer 입력
	{
		string buf;

		getline(cin, buf);
		cout << cin.gcount() << " " << buf << endl;	// string buffer 사용하면 gcount = 0
	}

	// cin.ignore(2)	: 입력받을 때 2글자 무시
	// cin.peek()		: buffer에서 가장 먼저 읽어올 글자 들여다보기 (꺼내지 않음)
	// cin.unget()		: 마지막에 읽은 글자를 buffer에 도로 집어넣음
	// cin.putback('A') : 'A'를 buffer에 집어넣음
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