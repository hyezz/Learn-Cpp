#include <iostream>

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// char type instantiation 할 때 사용하도록
template<>
char getMax(char x, char y)
{
	cout << "Warning: comparing chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax('a', 'b') << endl;

	return 0;
}