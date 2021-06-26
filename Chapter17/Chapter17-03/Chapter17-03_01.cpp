#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("01234567");
	// c-style ���ڿ����� null character�� �ϳ� ��������
	// string�� ���������� ���̸� ���� ������ �־ null�� ������ �������� ����
	//string my_str;
	//string my_str("");

	cout << boolalpha;
	cout << my_str.empty() << endl;		// false
	cout << my_str.size() << endl;		// 8
	cout << my_str.length() << endl;	// 8
	cout << my_str.capacity() << endl;	// 15 (���� �����Ͱ� �߰��� ���ɼ��� ����ؼ� memory reallocation ���Ϸ��� ������ �뷮 Ȯ��)
	cout << my_str.max_size() << endl;	// 2147483647

	my_str.reserve(1000);	// �̸� �뷮 Ȯ��
	cout << my_str.capacity() << endl;	// 1007

	return 0;
}