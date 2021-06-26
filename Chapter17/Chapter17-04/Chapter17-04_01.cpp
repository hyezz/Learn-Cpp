#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");

	// 문자 접근
	// [] : 퍼포먼스 good, at() : 안정성 good
	{
		cout << my_str[0] << endl;	// a
		cout << my_str[3] << endl;	// d

		my_str[3] = 'Z';

		try
		{
			//my_str[100] = 'X';	// runtime error (operator [] overloading 예외처리 안해줌)
			my_str.at(100) = 'X';	// throw exception
		}
		catch (exception& e)
		{
			cout << e.what() << endl;	// invalid string position
		}

		cout << my_str << endl;
	}

	// string -> c-style array 변환
	{
		// 1) c_str(), data() : 맨 끝에 null character 추가 (c-style처럼 사용 가능)
		cout << my_str.c_str() << endl;

		//const char* arr = my_str.c_str();
		const char* arr = my_str.data();	// c_str()과 비슷
		cout << (int)arr[6] << endl;	// 103
		cout << (int)arr[7] << endl;	// 0

		// 2) copy() : buffer에 복사 (null character 자동으로 안 넣음)
		char buf[20];

		my_str.copy(buf, 5, 1);	// 1번째부터 5만큼 복사

		buf[5] = '\0';	// null character 추가

		cout << buf << endl;
	}

	return 0;
}