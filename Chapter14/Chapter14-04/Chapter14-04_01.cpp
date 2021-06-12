#include <iostream>
#include <exception>
#include <string>

using namespace std;


class CustomException : public exception
{
public:
	const char* what() const noexcept override	// C++11 이상에서는 noexcept 넣어야 함
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		string s;
		//s.resize(-1);

		//throw runtime_error("Bad thing happend");

		throw CustomException();
	}
	catch (length_error& exception)
	{
		cout << "Length_Error" << endl;
		cerr << exception.what() << endl;
	}
	catch (exception& exception)
	{
		cout << typeid(exception).name() << endl;
		cerr << exception.what() << endl;
	}

	return 0;
}