#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string ToString(T x)
{
	ostringstream osstream;
	osstream << x;	// stringstream에 x 넣음
	return osstream.str();	// 들어온 x를 string 으로 바꿔서 리턴
}

template <typename T>
bool FromString(const string& str, T& x)
{
	istringstream isstream(str);	// string으로 stringstream 초기화
	return (isstream >> x) ? true : false;
}

int main()
{
	// 여러가지 생성자
	{
		string my_string("my string");			// c-style 문자열 초기화
		//const char* my_string = "my string";
		string second_string(my_string);		// 복사 생성
		string third_string(my_string, 3, 5);	// 3번째부터 5만큼 복사
		string fourth_string(10, 'A');			// 'A'를 10만큼 복사

		vector<char> vec;
		for (auto e : "Today is a good day.")	// iterator 초기화
			vec.push_back(e);
		string fifth_string(vec.begin(), vec.end());
		string sixth_string(vec.begin(), find(vec.begin(), vec.end(), 'y'));	// 'y' 찾아서 그 위치까지 복사

		cout << my_string << endl;
		cout << second_string << endl;
		cout << third_string << endl;	// strin
		cout << fourth_string << endl;	// AAAAAAAAAA
		cout << fifth_string << endl;	// Today is a good day.
		cout << sixth_string << endl;	// Toda
	}
	
	// 형변환
	{
		// 숫자 -> 문자열
		string my_str(to_string(1004));	// 정수 -> 문자열
		my_str += to_string(128);

		string my_str2(ToString(3.141592));	// T -> string

		string my_str3("Hello");	// FromString 불가능

		cout << my_str << endl;
		cout << my_str2 << endl;

		// 문자열 -> 숫자
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