#include <iostream>

using namespace std;

int main()
{
	//int my_array[5] = {1, 2, 3, 4, 5};
	//int my_array[5] = {1, 2, }; // ������ 0���� �ʱ�ȭ 
	int my_array[]{ 1, 2, 3, 4, 5 }; // C++11���ʹ� ������ ��Ȯ�ϸ� 5 ���� ���� 

	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << my_array[2] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	return 0;
}