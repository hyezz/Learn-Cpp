#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// set flag : + 기호, 진법
	{
		cout.setf(std::ios::showpos);	// show +
		cout << 108 << endl;

		cout.unsetf(std::ios::showpos);	// not show +
		cout << 108 << endl;

		cout.unsetf(std::ios::dec);	// 10진수 off
		cout.setf(std::ios::hex);	// 16진수 on
		cout << 108 << endl;

		cout.setf(std::ios::hex, std::ios::basefield);	// basefield에서 hex set
		cout << 108 << endl;

		cout.setf(std::ios::uppercase);	// 대문자
		//cout << std::hex << std::uppercase	// 대문자
		cout << std::hex;	// 16진수
		cout << 108 << endl;
		cout << 109 << endl;

		cout << std::dec;	// 10진수
		cout << 110 << endl;
	}
	
	// boolalpha
	{
		cout << std::boolalpha;	// true, false 문자열로 출력 (boolalpha 없으면 1, 0)
		cout << true << " " << false << endl;
	}

	// defaultfloat, fixed, scientific, showpoint : 자릿수
	{
		//cout << std::defaultfloat;
		//cout << std::fixed;	// 소수점 뒷자리 고정
		//cout << scientific << std::uppercase;	// E+02 : 10의 2승
		cout << std::showpoint;	// 소수점 첫째자리 없어도 . 보임
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
	}
	
	// setw(), left, right, internal, fill() : 빈칸 채우기
	{
		cout << -12345 << endl;
		cout.fill('*');	// *로 빈칸 채우기
		cout << std::setw(10) << -12345 << endl;	// 10자리 채우기
		cout << std::setw(10) << std::left << -12345 << endl;	// 왼쪽부터 10자리 채우기
		cout << std::setw(10) << std::right << -12345 << endl;	// 오른쪽부터 10자리 채우기
		cout << std::setw(10) << std::internal << -12345 << endl;	// 10자리 채우기 (부호와 숫자 사이 빈칸)
	}	

	return 0;
}