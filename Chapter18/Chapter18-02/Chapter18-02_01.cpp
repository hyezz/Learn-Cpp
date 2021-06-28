#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// set flag : + ��ȣ, ����
	{
		cout.setf(std::ios::showpos);	// show +
		cout << 108 << endl;

		cout.unsetf(std::ios::showpos);	// not show +
		cout << 108 << endl;

		cout.unsetf(std::ios::dec);	// 10���� off
		cout.setf(std::ios::hex);	// 16���� on
		cout << 108 << endl;

		cout.setf(std::ios::hex, std::ios::basefield);	// basefield���� hex set
		cout << 108 << endl;

		cout.setf(std::ios::uppercase);	// �빮��
		//cout << std::hex << std::uppercase	// �빮��
		cout << std::hex;	// 16����
		cout << 108 << endl;
		cout << 109 << endl;

		cout << std::dec;	// 10����
		cout << 110 << endl;
	}
	
	// boolalpha
	{
		cout << std::boolalpha;	// true, false ���ڿ��� ��� (boolalpha ������ 1, 0)
		cout << true << " " << false << endl;
	}

	// defaultfloat, fixed, scientific, showpoint : �ڸ���
	{
		//cout << std::defaultfloat;
		//cout << std::fixed;	// �Ҽ��� ���ڸ� ����
		//cout << scientific << std::uppercase;	// E+02 : 10�� 2��
		cout << std::showpoint;	// �Ҽ��� ù°�ڸ� ��� . ����
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
	}
	
	// setw(), left, right, internal, fill() : ��ĭ ä���
	{
		cout << -12345 << endl;
		cout.fill('*');	// *�� ��ĭ ä���
		cout << std::setw(10) << -12345 << endl;	// 10�ڸ� ä���
		cout << std::setw(10) << std::left << -12345 << endl;	// ���ʺ��� 10�ڸ� ä���
		cout << std::setw(10) << std::right << -12345 << endl;	// �����ʺ��� 10�ڸ� ä���
		cout << std::setw(10) << std::internal << -12345 << endl;	// 10�ڸ� ä��� (��ȣ�� ���� ���� ��ĭ)
	}	

	return 0;
}