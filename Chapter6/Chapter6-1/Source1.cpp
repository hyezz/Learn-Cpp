#include <iostream>

using namespace std;

int main()
{
	int one_student_score;	// 1 variable
	int student_scores[5];	// 5 int 

	cout << sizeof(one_student_score) << endl;	// 4
	cout << sizeof(student_scores) << endl;		// 4*5=20

	student_scores[0] = 100;	// 1st element
	student_scores[1] = 80;		// 2nd element
	student_scores[2] = 90;		// 3rd element
	student_scores[3] = 50;		// 4th element
	student_scores[4] = 0;		// 5th element
	student_scores[5] = 30;		// 6th element

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	cout << student_scores[5] << endl; // 런타임 에러 발생, 실행은 된다. 

	return 0;
}