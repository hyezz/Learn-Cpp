#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		// destructor에서는 throw exception 불가 (runtime error)
		//throw "error";
	}
};

int main()
{
	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i); // 스마트 포인터 쓰면 delete 필요없음 (알아서 메모리 지워줌)

		// do something with i
		throw "error";

		delete[] i;	// memory leak 발생

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}