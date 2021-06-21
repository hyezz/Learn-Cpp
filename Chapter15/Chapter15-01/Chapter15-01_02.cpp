#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initialization

int main()
{
	AutoPtr<Resource> res1(new Resource);
	AutoPtr<Resource> res2;

	cout << std::boolalpha;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	res2 = res1;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	return 0;
}