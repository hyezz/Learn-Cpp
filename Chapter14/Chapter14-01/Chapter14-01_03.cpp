#include <iostream>
#include <string>

using namespace std;

int main()
{
	try
	{
		// something happened
		//throw 1;
		//throw - 1.0;
		//throw "My error message";
		throw string("My error message");
	}
	// throw type에 맞게 catch (알맞은 type 없으면 runtime error 발생)
	catch (int x)
	{
		cout << "Catch integer " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout << "Char * " << error_message << endl;
	}
	catch(string error_message)
	{
		cout << error_message << endl;
	}

	return 0;
}