#include <iostream>

using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	// member function에서도 exception throw 가능
	int& operator[] (const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	// ArrayException가 먼저 나오지 않으면 Exception에 먼저 잡힘
	// 'ArrayException &': is caught by base class ('Exception &')
	//catch (ArrayException& e)
	//{
	//	cout << "doSomething()" << endl;
	//	e.report();
	//	throw e;	// 바깥으로 throw exception
	//}
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw;	// 객체 잘림 없이 바깥으로 throw exception
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}