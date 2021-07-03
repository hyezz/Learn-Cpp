#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterClassification(const int& i)
{
	cout << boolalpha;
	// <cctype> character classification functions
	cout << "isalnum " << bool(isalnum(i)) << endl;
	cout << "isblank " << bool(isblank(i)) << endl;
	cout << "isdigit " << bool(isdigit(i)) << endl;
	cout << "islower " << bool(islower(i)) << endl;
	cout << "isupper " << bool(isupper(i)) << endl;
}

// ios& stream: filestream(파일), iostream(콘솔) 공통적으로 사용 가능
void printStates(const ios& stream)
{
	cout << boolalpha;
	// state flag functions
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;	// end of file: 파일 다 읽었는지
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

bool isAllDigit(const string& str)
{
	bool ok_flag = true;

	for(auto e : str)
		if (!isdigit(e))	// 한글자씩 확인
		{
			ok_flag = false;
			break;
		}

	return ok_flag;
}

void classifyCharacters(const string& str)
{
	for (auto e : str)
	{
		cout << e << endl;
		cout << "isdigit " << isdigit(e) << endl;
		cout << "isblank " << isblank(e) << endl;
		cout << "isalpha " << isalpha(e) << endl;
	}
}

int main()
{
	while (true)
	{
		//int i;
		char i;
		cin >> i;

		printStates(cin);

		//cout << i << endl;	// 123.456을 넣으면 소수부 절삭하고 123 리턴

		//cout << boolalpha;
		//cout << bitset<8>(cin.rdstate()) << endl;	// int return
		//cout << bitset<8>(istream::goodbit) << endl;
		//cout << bitset<8>(istream::failbit) << endl;

		// rdstate로 읽어온 flag로부터 failbit mask를 이용해서 현재 상태 추출 (c-style)
		// goodbit을 사용하면 00000000인 경우 상태 추출이 안되므로 failbit으로 상태 추출하고 !(not)으로 판단
		//cout << !bool((cin.rdstate() & istream::failbit) != 0) << endl;

		printCharacterClassification(i);

		cin.clear();	// buffer 초기화
		cin.ignore(1024, '\n');
		cout << endl;
	}

	cout << boolalpha;
	cout << isAllDigit("1234") << endl;
	cout << isAllDigit("a1234") << endl;

	classifyCharacters("1234");
	classifyCharacters("a 1234");

	return 0;
}