#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	// os << "Hello" : buffer에 계속 덧붙임
	// os.str("Hello") : buffer 교체
	{
		stringstream os;

		os << "Hello, World!";	// << : insertion operator, >> : extraction operator
		os << "Hello, World!2" << endl;	// endline 포함 가능
		//os.str("Hello, World!\n");	// 줄바꿈 포함 가능

		string str;

		//os >> str;	// Hello, (빈칸에서 자름)
		str = os.str();	// string 통째로 가져옴
		cout << str << endl;
		//cout << os.str() << endl;
	}
	
	{
		stringstream os;

		// buffer에 저장

		// 1) 문자열
		//os << "12345 67 89";

		// 2) 숫자를 문자열로 저장
		int i = 12345;
		double d = 67.89;

		os << i << d;
		//os << i << " " << d;

		// buffer 출력

		// 1) 문자열 (빈칸 기준으로 나눔)
		string str1;
		string str2;

		//os >> str1 >> str2;
		//cout << str1 << "|" << str2 << endl;

		// 2) buffer를 숫자로 출력 
		int i2;
		double d2;

		os >> i2 >> d2;
		cout << i2 << "|" << d2 << endl;
	}

	// stringstream 초기화
	{
		stringstream os;

		os << "12345 67.89";

		// os.str() overloading
		os.str("");		// 파라미터 있을 때는 buffer 덮어씀
		cout << os.str() << endl;	// 파라미터 없을 때는 리턴

		// stringstream 초기화
		os.str("");
		os.str(string());
		os.clear();	// state 초기화 (stringstream 초기화 X)

		cout << os.str() << endl;
	}

	return 0;
}