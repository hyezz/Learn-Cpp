#include <iostream>
#include "Resource.h"

int main()
{
	Resource* res = new Resource(3);
	res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);	// 다른 데서 메모리를 할당받고 그 포인터를 넣어서 초기화
		auto ptr1 = std::make_shared<Resource>(3);	// 직접적으로 초기화 (make_shared 사용하는 게 좋음)
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr<Resource> ptr2(res);	// 이렇게 사용하면 안됨
			auto ptr2 = ptr1;	// 소유권을 몇 군데서 가지고 있는지 내부적으로 카운트 (마지막 포인터가 소멸될 때 Resource 지움)

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out ot the block" << std::endl;
		}

		ptr1->print();

		std::cout << "Going out ot the outer block" << std::endl;
	}
	
	std::getchar();

	return 0;
}