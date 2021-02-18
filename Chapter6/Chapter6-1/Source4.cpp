#include <iostream>

using namespace std;

enum StudentName
{
	JACKJACK, 		// = 0
	DASH,			// = 1
	VIOLET,			// = 2
	NUM_STUDENTS,	// = 3 (실제 element 개수) 
};

int main()
{
	int students_scores[NUM_STUDENTS];

	students_scores[JACKJACK] = 0;
	students_scores[DASH] = 100;

	return 0;
}