#include <iostream>
#include "Resource.h"

int main()
{
	Resource* res = new Resource(3);
	res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);	// �ٸ� ���� �޸𸮸� �Ҵ�ް� �� �����͸� �־ �ʱ�ȭ
		auto ptr1 = std::make_shared<Resource>(3);	// ���������� �ʱ�ȭ (make_shared ����ϴ� �� ����)
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr<Resource> ptr2(res);	// �̷��� ����ϸ� �ȵ�
			auto ptr2 = ptr1;	// �������� �� ������ ������ �ִ��� ���������� ī��Ʈ (������ �����Ͱ� �Ҹ�� �� Resource ����)

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