#include <iostream>

using namespace std;

int main()
{
	//int my_array[5] = {1, 2, 3, 4, 5};
	//int my_array[5] = {1, 2, }; // 나머지 0으로 초기화 
	int my_array[]{ 1, 2, 3, 4, 5 }; // C++11부터는 개수가 명확하면 5 생략 가능 

	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << my_array[2] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	return 0;
}