#include <iostream>

using namespace std;

//void last()
//void last() throw()		// not throw
//void last() throw(int)	// int type throw
void last() throw(...)	// all throw
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	//throw - 1;
	throw 'a';	// catch (...) 없으면 runtime error 발생

	cout << "End last " << endl;
}

void third()
{
	cout << "Third" << endl;

	last();

	cout << "End Third " << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught int exception" << endl;
	}

	cout << "End Second " << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	//catch (int)
	catch (double)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first " << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...)	// catch-all handlers
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	return 0;
}