#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findFirstChar(const char* string, char ch)
{
	for (size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;

	return -1;	// no match
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = false;
	return static_cast<double>(x) / y;
}

int main()
{
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		cerr << "An error occurred" << endl;
	else
		cout << "Result is " << result << endl;

	ifstream input_file("temp.txt");
	if (!input_file)
		cerr << "Cannot open file" << endl;

	return 0;
}