#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initialization

void doSomething()
{
	// 1) early return
	/*Resource* res = new Resource;

	if (true) return;

	delete res;

	return;*/

	// 2) throw exception
	try
	{
		//Resource* res = new Resource;	// dull pointer
		AutoPtr<Resource> res = new Resource;	// smart pointer

		if (true)
		{
			throw - 1;
		}

		//delete res;
	}
	catch (...)
	{
		
	}
	return;
}

int main()
{
	doSomething();

	return 0;
}