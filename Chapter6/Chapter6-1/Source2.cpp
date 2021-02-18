#include <iostream>

using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	cout << sizeof(Rectangle) << endl; // 4*2 = 8

	// 구조체 배열
	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl; // 8*10 = 80

	return 0;
}