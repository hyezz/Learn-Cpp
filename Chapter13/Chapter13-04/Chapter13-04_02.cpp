#include <iostream>
#include "Storage.h"
#include "Storage.cpp"

using namespace std;

int main()
{
	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}