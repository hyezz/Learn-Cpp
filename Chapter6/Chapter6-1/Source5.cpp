#include <iostream>

using namespace std;

int main()
{
	int num_students = 0;
	cin >> num_students; // num_students 값은 런타임 때 결정 

	int students_scores[num_students]; // ERROR: array 크기는 컴파일할 때 결정

	return 0;
}