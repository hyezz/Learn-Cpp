#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		// destructor������ throw exception �Ұ� (runtime error)
		//throw "error";
	}
};

int main()
{
	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i); // ����Ʈ ������ ���� delete �ʿ���� (�˾Ƽ� �޸� ������)

		// do something with i
		throw "error";

		delete[] i;	// memory leak �߻�

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}